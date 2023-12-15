/** @noSelfInFile */

/**
 * Defold native extension with math functions for use in Lua scripts.
 * @noResolution
 */
declare namespace emath {
	/**
	 * Restricts a number to be within a specified range.
	 * @param input Number to clamp
	 * @param lower Lower bound
	 * @param upper Upper bound
	 */
	export function clamp(input: number, lower: number, upper: number): number;
	/**
	 * Rounds a number to the nearest integer.
	 * @param input Number to round
	 */
	export function round(input: number): number;
}
