

#ifndef _HPP_Simulator_
#define _HPP_Simulator_

#include "Draw.hpp"
#include "Environment.hpp"

namespace Yogi { namespace Simulator {

class Simulator
{
public:
	Simulator();
	virtual ~Simulator();

public:
	int
	main( int argc, char** argv );
};

}} // namespace Yogi::Simulator

#endif // _HPP_Simulator_