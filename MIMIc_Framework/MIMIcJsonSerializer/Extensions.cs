using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MIMIcJsonSerializer.Extensions
{
    static class Extensions
    {
        #region MEMBER METHODS

        public static void WriteEncodedString(this BinaryWriter writer, System.Text.Encoding encoding, string str)
        {
            writer.Write(encoding.GetBytes(str));
        }

        public static void NewLine(this BinaryWriter writer)
        {
            writer.Write(Environment.NewLine);
        }

        #endregion
    }
}
