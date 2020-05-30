#include "nlohmann/json.hpp"

#include "gtest/gtest.h"

#include <fstream>

using json = nlohmann::json;

TEST( simulator, jsonRead )
{
	std::ifstream ifs( "environment.json" );

	if ( ifs )
	{
		json jf = json::parse( ifs );

		auto const jTerrain = jf["terrain"];
		if ( ! jTerrain.empty() )
		{
			int nRows = jTerrain["rows"];
			int nColumns = jTerrain["columns"];
			int nRowSpacing = jTerrain["rowSpacing"];
			int nColSpacing = jTerrain["colSpacing"];

			auto const jElevations = jTerrain["elevations"];
			if ( ! jElevations.empty() )
			{
				int nLenRows = jElevations.size();
				for ( auto jRow = jElevations.begin(); jRow != jElevations.end(); ++jRow )
				{
					if ( jRow->is_array() )
					{
						int nLenCols = jRow->size();
						std::cout << "[";
						for ( auto jCol = jRow->begin(); jCol != jRow->end(); ++jCol )
						{
							double d = jCol.value();
							std::cout << "  " << d;
						}
						std::cout << "  ]" << std::endl;
					}
				}
			}
		}
	}
}

TEST( Simulator, doubleDimensionArray )
{}
