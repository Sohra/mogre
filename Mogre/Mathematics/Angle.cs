﻿using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace Mogre
{
    public struct Angle : IEquatable<Angle>, IComparable<Angle>
    {
        readonly float _value;

        public Angle(float value)
        {
            _value = value;
        }

        public static implicit operator Radian(Angle angle)
        {
            Radian result = new Radian(MathHelper.AngleUnitsToRadians(angle._value));
            return result;
        }

        public static implicit operator Degree(Angle angle)
        {
            Degree result = new Degree(MathHelper.AngleUnitsToDegrees(angle._value));
            return result;
        }

        public int CompareTo(Angle other)
        {
            if (_value < other._value) return -1;
            if (_value > other._value) return 1;
            return 0;
        }

        /// <summary>
		/// Returns a boolean indicating whether the given Vector2 is equal to this Vector2 instance.
		/// </summary>
		/// <param name="other">The Vector2 to compare this instance to.</param>
		/// <returns>True if the other Vector2 is equal to this instance; False otherwise.</returns>
		public bool Equals(ref Angle other)
        {
            return _value == other._value;
        }

        /// <summary>
        /// Returns a boolean indicating whether the given Vector2 is equal to this Vector2 instance.
        /// </summary>
        /// <param name="other">The Vector2 to compare this instance to.</param>
        /// <returns>True if the other Vector2 is equal to this instance; False otherwise.</returns>
        public bool Equals(Angle other)
        {
            return Equals(ref other);
        }

        /// <summary>
        /// Returns a boolean indicating whether the given Object is equal to this Vector2 instance.
        /// </summary>
        /// <param name="obj">The Object to compare against.</param>
        /// <returns>True if the Object is equal to this Vector2; False otherwise.</returns>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public override bool Equals(object obj)
        {
            if (!(obj is Angle))
                return false;

            return Equals((Angle)obj);
        }

        /// <summary>
		/// Returns the hash code for this instance.
		/// </summary>
		/// <returns>The hash code.</returns>
		public override int GetHashCode()
        {
            return _value.GetHashCode();
        }
    }
}
