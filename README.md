# defold-emath

Defold native extension with math functions for use in Lua scripts.

You may instead prefer [DefMath](https://github.com/subsoap/defmath) for a most robust implementation.

## Functions

- `emath.clamp(number, lower, upper)`
- Restricts a number to be within a specified range.

- `emath.round(number)`
- Rounds a number to the nearest integer.

- `emath.sign(number)`
- Returns the sign of a number (-1 for negative, 1 for positive, 0 for zero).

- `emath.deg_to_rad(degrees)`
- Converts degrees to radians.

- `emath.rad_to_deg(radians)`
- Converts radians to degrees.

- `emath.distance2d(x1, y1, x2, y2)`
- Calculates the 2D distance between two points.

- `emath.distance3d(x1, y1, z1, x2, y2, z2)`
- Calculates the 3D distance between two points.

## Installation

This extension includes types for use with [TypeScript + Defold](https://ts-defold.dev/).

1. Edit game.project
2. Add dependency `https://github.com/thinknathan/defold-emath/archive/main.zip` for the current version
   - Or add a specific [release](https://github.com/thinknathan/defold-emath/releases)

### TypeScript Definitions

1. Install these types

```bash
yarn add git+https://git@github.com/thinknathan/defold-emath.git#^2.0.0 -D
# or
npm install git+https://git@github.com/thinknathan/defold-emath.git#^2.0.0 --save-dev
```

2. Add `defold-emath` to `types` in `tsconfig.json`

```diff
{
	"compilerOptions": {
		"types": [
+			"defold-emath",
		],
	}
}
```

3. Add `node_modules/@types` to `typeRoots` in `tsconfig.json` if it's not already there

```diff
{
	"compilerOptions": {
		"typeRoots": [
+			"node_modules/@types",
		],
	}
}
```

## Usage

```lua
-- clamp
-- Restricts a number to be within a specified range.
local clampedValue = emath.clamp(25, 10, 20)
print(clampedValue)  -- Output: 20

-- round
-- Rounds a number to the nearest integer.
local roundedValue = emath.round(15.75)
print(roundedValue)  -- Output: 16

-- sign
-- Returns the sign of a number (-1 for negative, 1 for positive, 0 for zero).
local signValue = emath.sign(-7)
print(signValue)  -- Output: -1

-- deg_to_rad
-- Converts degrees to radians.
local radians = emath.deg_to_rad(90)
print(radians)  -- Output: 1.5708 (approximately)

-- rad_to_deg
-- Converts radians to degrees.
local degrees = emath.rad_to_deg(3.14159)
print(degrees)  -- Output: 180

-- distance2d
-- Calculates the 2D distance between two points.
local distance = emath.distance2d(0, 0, 3, 4)
print(distance)  -- Output: 5

-- distance3d
-- Calculates the 3D distance between two points.
local distance = emath.distance3d(0, 0, 0, 3, 4, 5)
print(distance)  -- Output: 7.0711 (approximately)
```

## Background

This project is an experiment with generating a Defold extension using Chat-GPT 3.5. The prompt was as follows:

```
create a defold extension that exposes a module to lua, use c++ that does not use any features newer than 2009, and does not use the standard library. the name of the module is emath. it should have a function called clamp exposed to lua that receives a number from lua, as well as an upper and lower bound from lua, and if the first number is larger than the upper it will be made the same as the upper, or if it is smaller than the lower it will be made the same as the lower, the final number will be returned to lua. it should have a function called round exposed to lua that receives a number, rounds it to the nearest integer, and returns it to lua.
```

Further adjustments were made for v2.0.0.
