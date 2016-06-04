using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateTextBoundingData
{
    class TextTypeBoundingData
    {
        #region MEMBER FIELDS

        List<TextType> m_types = new List<TextType>();

        #endregion


        #region MEMBER CLASSES

        public class TextType
        {
            #region MEMBER FIELDS

            List<BoundingData> m_boundingData = new List<BoundingData>();

            #endregion


            #region MEMBER CLASSES

            public class BoundingData
            {

                public byte CharacterX
                {
                    get;
                    set;
                }

                public byte CharacterY
                {
                    get;
                    set;
                }

                public byte[][] Texture
                {
                    get;
                    set;
                }
            }

            #endregion


            #region MEMBER PROPERTIES

            public string Type
            {
                get;
                set;
            }

            public List<BoundingData> Characters
            {
                get { return m_boundingData; }
            }

            #endregion
        }

        #endregion


        #region MEMBER PROPERTIES

        public byte CharacterWidth
        {
            get;
            set;
        }

        public byte CharacterHeight
        {
            get;
            set;
        }

        public List<TextType> Types
        {
            get { return m_types; }
        }

        #endregion
    }
}
