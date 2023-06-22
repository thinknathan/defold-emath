# defold-emath
Defold math extension with clamp and round utility functions.

You may prefer [DefMath](https://github.com/subsoap/defmath) for a most robust implementation.

## Installation

1. Edit game.project
2. Add dependency `https://github.com/thinknathan/defold-emath/archive/main.zip` for the current version
    - Or add a specific [release](https://github.com/thinknathan/defold-emath/releases)

### TypeScript Definitions

1. Install these types

```bash
yarn add git+https://git@github.com/thinknathan/defold-emath.git#^1.0.0 -D
# or
npm install git+https://git@github.com/thinknathan/defold-emath.git#^1.0.0 --save-dev
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
-- main.script
function init(self)
    local number = 15
    local lower = 10
    local upper = 20

    -- Ensures the given number is not less than lower or larger than upper
    local result = emath.clamp(number, lower, upper)
    print(result)  -- Output: 15

    local number2 = 3.7
    -- Rounds number to the nearest integer
    local rounded = emath.round(number2)
    print(rounded)  -- Output: 4
end
```

## Background

This project is an experiment with generating a Defold extension using Chat-GPT. The prompt was as follows:

```
create a defold extension that exposes a module to lua, use c++ that does not use any features newer than 2009, and does not use the standard library. the name of the module is emath. it should have a function called clamp exposed to lua that receives a number from lua, as well as an upper and lower bound from lua, and if the first number is larger than the upper it will be made the same as the upper, or if it is smaller than the lower it will be made the same as the lower, the final number will be returned to lua. it should have a function called round exposed to lua that receives a number, rounds it to the nearest integer, and returns it to lua.
```
