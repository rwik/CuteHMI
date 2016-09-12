#ifndef CUTEHMI_LIBMODBUS_SRC_MODBUS_ABSTRACTCONNECTION_HPP
#define CUTEHMI_LIBMODBUS_SRC_MODBUS_ABSTRACTCONNECTION_HPP

#include <cstdint>

namespace cutehmi {
namespace modbus {

class AbstractConnection
{
	public:
		virtual ~AbstractConnection() = default;

		virtual bool connect() = 0;

		virtual void disconnect() = 0;

		virtual int readIr(int addr, int num, uint16_t * dest) = 0;

		virtual int readR(int addr, int num, uint16_t * dest) = 0;

		virtual int writeR(int addr, uint16_t value) = 0;

		/**
		 * Read discrete inputs.
		 * @param addr address of first discrete input to read.
		 * @param num number of inputs to read.
		 * @param dest destination pointer. Array must have sufficient space allocated to store @num elements.
		 * @return number of inputs read or -1 in case of error.
		 *
		 * @internal One could use std::vector<bool> or other space-efficient type for @a dest array, but
		 * bool pointer is more flexible (as it can interoperate with many data types).
		 */
		virtual int readIb(int addr, int num, bool * dest) = 0;

		virtual int readB(int addr, int num, bool * dest) = 0;

		virtual int writeB(int addr, bool value) = 0;

	protected:
		AbstractConnection() = default;
};

}
}

#endif
