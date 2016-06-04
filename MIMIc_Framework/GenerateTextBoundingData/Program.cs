using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media.Imaging;

using MIMIcJsonSerializer;

namespace GenerateTextBoundingData
{
    class Program
    {
        static List<string> s_messages = new List<string>();

        static void Main(string[] args)
        {
            bool go = true;

            var imagesTextDirectory = args[0];
            if (!Directory.Exists(imagesTextDirectory))
            {
                s_messages.Add("Please provide a valid data directory (images\text) as arg[0].");
                go = false;
            }

            var styleDirectory = args[1];
            if(!Directory.Exists(Path.Combine(imagesTextDirectory, styleDirectory)))
            {
                s_messages.Add("Please provide a valid data directory (style) as arg[1].");
                go = false;
            }

            var datDirectory = args[2];

            byte width = 0,
                height = 0;
            if (!byte.TryParse(args[3], out width) || !byte.TryParse(args[4], out height))
            {
                s_messages.Add("Please provide a valid integer value (width, height) for arg [3] and arg[4].");
                go = false;
            }

            if (go)
            {
                TextTypeBoundingData tbd = new TextTypeBoundingData() { CharacterWidth = width, CharacterHeight = height };

                var imagesTextStyleDirectory = Path.Combine(imagesTextDirectory, styleDirectory);
                foreach (var pngFile in Directory.GetFiles(imagesTextStyleDirectory, "*.png"))
                {
                    // each text type is based on the name of the file
                    var textType = 
                        new TextTypeBoundingData.TextType()
                        {
                            Type = Path.GetFileNameWithoutExtension(pngFile)
                        };

                    // create a bitmap
                    var bitmap = new BitmapImage(new Uri(pngFile));

                    //if ((bitmap.PixelWidth % width) != 0)
                    //{
                    //    s_messages.Add(string.Format("{0} pixel width not a multiple of {1}.", pngFile, width));
                    //    continue;
                    //}

                    if ((bitmap.PixelHeight % height) != 0)
                    {
                        s_messages.Add(string.Format("{0} pixel height not a multiple of {1}.", pngFile, height));
                        continue;
                    }

                    byte numHorizontal = (byte)(bitmap.PixelWidth / width);
                    byte numVertical = (byte)(bitmap.PixelHeight / height);

                    for (byte y = 0; y < numVertical; ++y)
                    {
                        for (byte x = 0; x < numHorizontal; ++x)
                        {
                            byte[][] dataArray = new byte[width][];
                            for (int arr = 0; arr < width; ++arr)
                                dataArray[arr] = new byte[height];

                            var croppedBitmap = new CroppedBitmap(bitmap, new Int32Rect(x * width, y * height, width, height));

                            int stride = croppedBitmap.PixelWidth * 4;
                            int size = croppedBitmap.PixelHeight * stride;
                            byte[] pixels = new byte[size];

                            croppedBitmap.CopyPixels(pixels, stride, 0);

                            int currentPixelIndex = 0;
                            int pixelIncrement = 4;
                            byte r, g, b, a;
                            int currentPixelX = 0;
                            int currentPixelY = 0;

                            bool anySuccess = false;
                            for (; currentPixelIndex < size; currentPixelIndex += pixelIncrement)
                            {
                                r = pixels[currentPixelIndex];
                                g = pixels[currentPixelIndex + 1];
                                b = pixels[currentPixelIndex + 2];
                                a = pixels[currentPixelIndex + 3];

                                int success = (r + g + b + a > 0) ? 1 : 0;
                                if (success == 1)
                                    anySuccess = true;
                                dataArray[currentPixelX][currentPixelY] = (success > 0) ? (byte)1 : (byte)0;

                                currentPixelX = (currentPixelX + 1) % width;
                                if (currentPixelX == 0)
                                    currentPixelY = currentPixelY + 1;
                            }

                            // if the entry is entirely zeros, we don't care about this one
                            if (!anySuccess)
                            {
                                s_messages.Add(string.Format("Skipping index {0}, {1} for {2}.", x, y, Path.GetFileName(pngFile)));
                                continue;
                            }

                            // add new character
                            textType.Characters.Add
                            (
                                new TextTypeBoundingData.TextType.BoundingData()
                                {
                                    CharacterX = x,
                                    CharacterY = y,
                                    Texture = dataArray
                                }
                            );
                        }
                    }

                    // done with this type
                    tbd.Types.Add(textType);

                    s_messages.Add(string.Format("Generation for {0} successful.", Path.GetFileName(pngFile)));
                }

                // write the bytes, very carefully
                using (var jsonFile = new JsonFile(Path.Combine(datDirectory, string.Format("{0}.dat", styleDirectory))))
                {
                    Serialize.Start(jsonFile);

                    Serialize.NamedBinaryValue(jsonFile, "characterWidth", tbd.CharacterWidth, true);
                    Serialize.NamedBinaryValue(jsonFile, "characterHeight", tbd.CharacterHeight, true);

                    Serialize.ArrayStart(jsonFile, "types");

                    for(int i = 0, j = tbd.Types.Count; i < j; ++i)
                    {
                        var type = tbd.Types[i];

                        Serialize.ObjectStart(jsonFile, null);

                        Serialize.NamedStringValue(jsonFile, "name", type.Type, true);

                        Serialize.ArrayStart(jsonFile, "data");

                        for(int ii = 0, jj = type.Characters.Count; ii < jj; ++ii)
                        {
                            var boundingData = type.Characters[ii];

                            Serialize.ObjectStart(jsonFile, null);

                            Serialize.NamedBinaryValue(jsonFile, "characterX", boundingData.CharacterX, true);
                            Serialize.NamedBinaryValue(jsonFile, "characterY", boundingData.CharacterY, true);

                            Serialize.ArrayStart(jsonFile, "data");

                            for (int y = 0; y < height; ++y)
                            {
                                for (int x = 0; x < width; ++x)
                                {
                                    Serialize.BinaryValue(jsonFile, boundingData.Texture[x][y]);
                                }

                                Serialize.NewLine(jsonFile);
                            }

                            Serialize.ArrayEnd(jsonFile, false);

                            Serialize.ObjectEnd(jsonFile, ii + 1 != jj);
                        }

                        Serialize.ArrayEnd(jsonFile, false);

                        Serialize.ObjectEnd(jsonFile, i + 1 != j);
                    }

                    Serialize.ArrayEnd(jsonFile, false);

                    Serialize.End(jsonFile);
                }
            }

            foreach (var message in s_messages)
                Console.WriteLine(message);
            Console.ReadKey();
        }
    }
}
