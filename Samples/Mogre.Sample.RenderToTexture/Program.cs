﻿// Alimer - Copyright (C) Amer Koleci
// This file is subject to the terms and conditions defined in
// file 'LICENSE.txt', which is part of this source code package.

using System.Runtime.InteropServices;

namespace Mogre.Framework
{
	class Program
	{
		static void Main(string[] args)
		{
			try
			{
				var app = new RenderToTextureSample();
				app.Run();
			}
			catch (SEHException)
			{
				if (!OgreException.IsThrown)
				{
					throw;
				}

				var ogreException = OgreException.LastException;
				//Example.ShowOgreException();
			}
		}
	}
}
