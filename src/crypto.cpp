#include "crypto.h"

std::string encrypt(std::string input, std::string password)
{
	std::string output;

	using namespace CryptoPP;

	StringSource ss1(input, true,
		new DefaultEncryptorWithMAC(
			(byte*)password.data(), password.size(),
			new HexEncoder(
				new StringSink(output)
			)
		)
	);

	return output;
}

std::string decrypt(std::string input, std::string password)
{
	std::string output;

	using namespace CryptoPP;

	StringSource ss1(input, true,
		new HexDecoder(
			new DefaultDecryptorWithMAC(
			(byte*)password.data(), password.size(),
				new StringSink(output)
			)
		)
	);

	return output;
}
