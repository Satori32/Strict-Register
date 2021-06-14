#include <iostream>
#include <cstdint>

// like a x86 register??

namespace Register {
	struct BYTE {
		BYTE() :UInt8(0) {}
		BYTE(const BYTE& In) :UInt8(In.UInt8) {}
		union
		{
			struct {
				std::uint8_t Bit00 : 1;
				std::uint8_t Bit01 : 1;
				std::uint8_t Bit02 : 1;
				std::uint8_t Bit03 : 1;
				std::uint8_t Bit04 : 1;
				std::uint8_t Bit05 : 1;
				std::uint8_t Bit06 : 1;
				std::uint8_t Bit07 : 1;
			};

			struct
			{
				std::uint8_t Int2A : 2;
				std::uint8_t Int2B : 2;
				std::uint8_t Int2C : 2;
				std::uint8_t Int2D : 2;
			};
			struct
			{
				std::uint8_t Int4A : 4;
				std::uint8_t Int4B : 4;
			};

			std::int8_t Int8 = 0;
			std::uint8_t UInt8;
		};
	};


	struct WORD
	{
		WORD():UInt16(0){}
		WORD(const WORD& In) :UInt16(In.UInt16) {}
		union {
			struct {
				BYTE BYTE01;
				BYTE BYTE02;
			};
			std::int16_t UInt16 = 0;
			std::uint16_t UInt16;
		};
	};
	struct DWORD
	{		
		DWORD():UInt32(0){}
		DWORD(const DWORD& In) :UInt32(In.UInt32) {}
		union {
			struct {
				WORD WORD01;
				WORD WORD02;
			};
			std::int32_t Int32 = 0;
			std::uint32_t UInt32;
		};
	};
	struct QWORD
	{	
		QWORD():UInt64(0){}
		QWORD(const QWORD& In) :UInt64(In.UInt64) {}
		union {
			struct {
				DWORD DWORD01;
				DWORD DWORD02;
			};
			std::int64_t Int64 = 0;
			std::uint64_t UInt64;
		};
	};
}

int main() {
	Register::QWORD QW;

	QW.DWORD01.WORD01.BYTE01.Bit00 = 1;
	QW.DWORD01.WORD01.BYTE01.Int2A = 2;
	return 0;
}