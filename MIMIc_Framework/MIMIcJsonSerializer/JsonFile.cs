using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MIMIcJsonSerializer
{
    public class JsonFile : IDisposable
    {
        #region MEMBER FIELDS

        FileStream m_fileStream;
        BinaryWriter m_writer;

        #endregion


        #region MEMBER PROPERTIES

        public string FileName
        {
            get;
            private set;
        }

        public BinaryWriter Writer
        {
            get { return m_writer; }
        }

        #endregion


        #region MEMBER METHODS

        #region Public Functionality

        public JsonFile(string fileName)
        {
            FileName = fileName;
            m_fileStream = new FileStream(FileName, FileMode.Create);
            m_writer = new BinaryWriter(m_fileStream);
        }

        public void Dispose()
        {
            m_writer.Dispose();
            m_fileStream.Dispose();
        }

        #endregion


        #region Private Functionality
        #endregion

        #endregion
    }
}
