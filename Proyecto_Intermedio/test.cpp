#define CATCH_CONFIG_MAIN
#include <cmath>
#include <fstream>
#include "catch2/catch.hpp"
#include "functions.hpp"


const int nmol = 400;

TEST_CASE("Compute entropy of the system", "[entropy]")
{
  double pos[nmol][2];
  double la[lattice][lattice];

  REQUIRE( std::isinf(entropy(0, pos, la))  == true );
  for(int i = 0 ; i <= 61 ; i++)
  {
    REQUIRE( entropy(64, pos, la) >= 0 );
    if(pos[i][0]==0 && pos[i][1]==0)
    {
    REQUIRE( entropy(nmol, pos, la) == 0);
    }
  }

  for(int i = 0 ; i < lattice ; i++)
  {
    for(int j = 0 ; j < lattice ; j++)
    {
      if (la[i][j] == 0)
      {
        REQUIRE(entropy(i, pos, la) == 0 );
      }
    }
  }
}
