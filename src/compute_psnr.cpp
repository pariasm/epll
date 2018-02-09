/*
 * Original work: Copyright (c) 2013, Marc Lebrun <marc.lebrun.ik@gmail.com>
 * Modified work: Copyright (c) 2014, Pablo Arias <pariasm@gmail.com>
 * Modified work: Copyright (c) 2016, Thibaud Ehret <ehret.thibaud@gmail.com>
 * All rights reserved.
 *
 * This program is free software: you can use, modify and/or
 * redistribute it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later
 * version. You should have received a copy of this license along
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <string>
#include <sstream>

#include "Utilities/Utilities.h"
#include "Utilities/cmd_option.h"
#include "Utilities/LibVideoT.hpp"

using namespace std;

/**
 * @file   compute_psnr.cpp
 * @brief  Compute the PSNR between two image
 *
 * @author THIBAUD EHRET <ehret.thibaud@gmail.com>
 **/

int main(int argc, char **argv)
{
	clo_usage("Compute PSNR");
	clo_help(" NOTE: Input (<) and output (>) sequences are specified by their paths in printf format.\n");

	//! Paths to input/output sequences
	using std::string;
	const string  input_path = clo_option("-i"    , ""              , "< input sequence");
	const string  inbsc_path = clo_option("-r"    , ""              , "< input sequence 2");
	int firstFrame = 1, lastFrame = 1, frameStep = 1;

	//! Declarations
	Video<float> original, final;

	//! Load input videos
	original.loadVideo(input_path, firstFrame, lastFrame, frameStep);
	final.loadVideo(inbsc_path, firstFrame, lastFrame, frameStep);

	float final_psnr = -1, final_rmse = -1, basic_psnr = -1, basic_rmse = -1;
	VideoUtils::computePSNR(original, final, final_psnr, final_rmse, 255.);
	printf("final PSNR =\t%f\tRMSE =\t%f\n", final_psnr, final_rmse);

	return EXIT_SUCCESS;
}
