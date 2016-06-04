using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using MIMIcJsonSerializer.Extensions;

namespace MIMIcJsonSerializer
{
    public static class Serialize
    {
        #region MEMBER FIELDS
        #endregion


        #region MEMBER PROPERTIES

        private static System.Text.Encoding FileEncoding
        {
            get { return System.Text.Encoding.ASCII; }
        }

        private static string OpenObject
        {
            get { return "{"; }
        }

        private static string CloseObject
        {
            get { return "}"; }
        }

        private static string OpenArray
        {
            get { return "["; }
        }

        private static string CloseArray
        {
            get { return "]"; }
        }

        #endregion


        #region MEMBER METHODS

        #region Public Functionality

        public static void Start(JsonFile file)
        {
            file.Writer.WriteEncodedString(FileEncoding, OpenObject);
            file.Writer.NewLine();
        }

        public static void End(JsonFile file)
        {
            file.Writer.WriteEncodedString(FileEncoding, CloseObject);
            file.Writer.NewLine();
        }

        public static void ObjectStart(JsonFile file, string objectName)
        {
            if (objectName != null)
                WriteJsonName(file, objectName);
            file.Writer.WriteEncodedString(FileEncoding, OpenObject);
            file.Writer.NewLine();
        }

        public static void ObjectEnd(JsonFile file, bool trailingComma)
        {
            file.Writer.WriteEncodedString(FileEncoding, CloseObject);
            if (trailingComma)
                file.Writer.WriteEncodedString(FileEncoding, ",");
            file.Writer.NewLine();
        }

        public static void ArrayStart(JsonFile file, string arrayName)
        {
            if (arrayName != null)
                WriteJsonName(file, arrayName);
            file.Writer.WriteEncodedString(FileEncoding, OpenArray);
            file.Writer.NewLine();
        }

        public static void ArrayEnd(JsonFile file, bool trailingComma)
        {
            file.Writer.WriteEncodedString(FileEncoding, CloseArray);
            if (trailingComma)
                file.Writer.WriteEncodedString(FileEncoding, ",");
            file.Writer.NewLine();
        }

        public static void NamedStringValue(JsonFile file, string valueName, string value, bool trailingComma)
        {
            WriteJsonName(file, valueName);
            file.Writer.WriteEncodedString(FileEncoding, string.Format("\"{0}\"", value));
            if (trailingComma)
                file.Writer.WriteEncodedString(FileEncoding, ",");
            file.Writer.NewLine();
        }

        public static void NamedBinaryValue(JsonFile file, string valueName, byte value, bool trailingComma)
        {
            WriteJsonName(file, valueName);
            file.Writer.Write(value);
            if (trailingComma)
                file.Writer.WriteEncodedString(FileEncoding, ",");
            file.Writer.NewLine();
        }

        public static void BinaryValue(JsonFile file, byte value)
        {
            file.Writer.Write(value);
        }

        public static void NewLine(JsonFile file)
        {
            file.Writer.NewLine();
        }

        #endregion


        #region Private Functionality

        static void WriteJsonName(JsonFile file, string jsonName)
        {
            file.Writer.WriteEncodedString(FileEncoding, string.Format("\"{0}\":", jsonName));
        }

        #endregion

        #endregion
    }
}
