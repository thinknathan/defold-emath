/** @noSelfInFile */

/**
 * Extended math native extension
 * @noResolution
 */
declare namespace emath {
	/**
	 * Ensures the `input` number is not less than `lower`, or larger than `upper`
	 * @param input
	 * @param lower
	 * @param upper
	 */
	export function clamp(input: number, lower: number, upper: number): number;
	/**
	 * Rounds the `input` number to the nearest integer
	 * @param input
	 */
	export function round(input: number): number;
}
