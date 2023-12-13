/// <library version="2.0.0" src="https://github.com/thinknathan/defold-emath/archive/refs/tags/v2.0.0.zip" />
/// <reference path="./emath.d.ts" />

/** @noSelfInFile */

/**
 * Extended math native extension
 * @noResolution
 */
declare namespace emath {
	/**
	 * Returns the sign of a number (1 for positive, -1 for negative, 0 for zero).
	 * @param number
	 */
	function sign(number: number): number;
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
	 * Calculates the distance between two points in 2D space.
	 * @param x1
	 * @param y1
	 * @param x2
	 * @param y2
	 */
	function distance2d(x1: number, y1: number, x2: number, y2: number): number;
	/**
	 * Calculates the distance between two points in 3D space.
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
