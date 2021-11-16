#include <SDL2/SDL.h>
#include <iostream>
#include <bitset>

// Entity is just an ID
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

// Each Component just has an ID
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;

// A simple type alias
using Signature = std::bitset<MAX_COMPONENTS>;