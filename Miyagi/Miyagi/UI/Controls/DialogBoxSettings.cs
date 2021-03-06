﻿/*
 Miyagi v1.2.1
 Copyright (c) 2008 - 2012 Tobias Bohnen

 Permission is hereby granted, free of charge, to any person obtaining a copy of this
 software and associated documentation files (the "Software"), to deal in the Software
 without restriction, including without limitation the rights to use, copy, modify, merge,
 publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 to whom the Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */
namespace Miyagi.UI.Controls
{
    using Miyagi.Common.Data;

    /// <summary>
    /// Represents settings for the <see cref="DialogBox"/>.
    /// </summary>
    public class DialogBoxSettings
    {
        #region Fields

        private readonly Size buttonSize;
        private readonly Point buttonTextOffset;
        private readonly Point labelTextOffset;
        private readonly Point location;
        private readonly Size size;

        #endregion Fields

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="DialogBoxSettings"/> class.
        /// </summary>
        /// <param name="buttonSize">Size of the button.</param>
        /// <param name="buttonTextOffset">The button text offset.</param>
        /// <param name="labelTextOffset">The label text offset.</param>
        /// <param name="location">The location.</param>
        /// <param name="size">The size.</param>
        public DialogBoxSettings(Size buttonSize, Point buttonTextOffset, Point labelTextOffset, Point location, Size size)
        {
            this.buttonSize = buttonSize;
            this.buttonTextOffset = buttonTextOffset;
            this.labelTextOffset = labelTextOffset;
            this.location = location;
            this.size = size;
        }

        #endregion Constructors

        #region Properties

        #region Public Properties

        /// <summary>
        /// Gets the size of the button.
        /// </summary>
        /// <value>The size of the button.</value>
        public Size ButtonSize
        {
            get
            {
                return this.buttonSize;
            }
        }

        /// <summary>
        /// Gets the button text offset.
        /// </summary>
        /// <value>The button text offset.</value>
        public Point ButtonTextOffset
        {
            get
            {
                return this.buttonTextOffset;
            }
        }

        /// <summary>
        /// Gets the label text offset.
        /// </summary>
        /// <value>The label text offset.</value>
        public Point LabelTextOffset
        {
            get
            {
                return this.labelTextOffset;
            }
        }

        /// <summary>
        /// Gets the location.
        /// </summary>
        /// <value>The location.</value>
        public Point Location
        {
            get
            {
                return this.location;
            }
        }

        /// <summary>
        /// Gets the size.
        /// </summary>
        /// <value>The size.</value>
        public Size Size
        {
            get
            {
                return this.size;
            }
        }

        #endregion Public Properties

        #endregion Properties
    }
}