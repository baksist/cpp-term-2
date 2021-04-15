#pragma once
#include <iostream>
#include "cryptopp/default.h"
#include "cryptopp/hex.h"

std::string encrypt(std::string input, std::string password);
std::string decrypt(std::string input, std::string password);
