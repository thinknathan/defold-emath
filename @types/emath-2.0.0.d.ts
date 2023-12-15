/// <library version="2.0.0" src="https://github.com/thinknathan/defold-emath/archive/refs/tags/v2.0.0.zip" />
/// <reference path="./emath.d.ts" />

/** @noSelfInFile */

/**
 * Defold native extension with math functions for use in Lua scripts.
 * @noResolution
 */
declare namespace emath {
	/**
	 * Returns the sign of a number (-1 for negative, 1 for positive, 0 for zero).
	 * @param input Number to check
	 */
	function sign(input: number): number;

	/**
	 * Converts degrees to radians.
	 * @param degrees
	 */
	function deg_to_rad(degrees: number): number;

	/**
	 * Converts radians to degrees.
	 * @param radians
	 */
	function rad_to_deg(radians: number): number;

	/**
	 * Calculates the 2D distance between two points.
	 * @param x1
	 * @param y1
	 * @param x2
	 * @param y2
	 */
	function distance2d(x1: number, y1: number, x2: number, y2: number): number;

	/**
	 * Calculates the 3D distance between two points.
	 * @param x1
	 * @param y1
	 * @param z1
	 * @param x2
	 * @param y2
	 * @param z2
	 */
	function distance3d(
		x1: number,
		y1: number,
		z1: number,
		x2: number,
		y2: number,
		z2: number,
	): number;
}
