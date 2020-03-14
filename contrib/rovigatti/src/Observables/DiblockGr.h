/*
 * Gyradius.h
 *
 *  Created on: Oct 30, 2013
 *      Author: Lorenzo
 */

#ifndef DIBLOCKGR_H_
#define DIBLOCKGR_H_

#include "Observables/ForceEnergy.h"

/**
 * @brief Computes the A-A, A-B, B-B and intramolecular g(r) of a two-chain diblock copolymer system
 *
 */

class DiblockGr: public BaseObservable {
protected:
	number _max_dist;
	number _bin;
	int _n_bins;
	int _n_conf;
	bool _biased;
	number _T;
	number *_inter_hist[3], *_intra_hist;
	number _inter_norm[3], _intra_norm;
	ForceEnergy _force_energy;
	bool _only_intra;

	int _get_bin(number sqr_dist);

public:
	enum {
		AA = 0, AB = 1, BB = 2
	};

	DiblockGr();
	virtual ~DiblockGr();

	void get_settings(input_file &my_inp, input_file &sim_inp);
	virtual void init(ConfigInfo &config_info);
	virtual std::string get_output_string(llint curr_step);
};

extern "C" BaseObservable *make_DiblockGr() {
	return new DiblockGr();
}

#endif /* DIBLOCKGR_H_ */
