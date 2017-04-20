#include "bintree.cpp"
#include <vector>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <complex>

using namespace bintree;

// Test balance of tree
int main(){

	std::vector<int> vec(9000);

	for(int i = 1; i<= 9000; ++i){
		vec[i-1] = i;
	}

	unsigned SEED = 911206;

	std::shuffle(vec.begin(),vec.end(),std::default_random_engine(SEED));

	std::vector<int> max_res(800);
	std::vector<int> min_res(800);

	// do this 800 times
	for(int i = 0; i<800; ++i){
		Node * root = nullptr;
		for(int n : vec){
			insert(root,n,n);
		}
		
		max_res[i] = max_height(root);
		min_res[i] = min_height(root);

		// free up memory
		delete_tree(root);
		std::next_permutation(vec.begin(),vec.end());		
		//std::shuffle(vec.begin(),vec.end(),std::default_random_engine(SEED));
	}

	double avg_height = 0.0;
	double max_height = 0.0;
	double min_height = 0.0;
	double avg_diff_height = 0.0;
	double max_diff_height = 0.0;
	double min_diff_height = 0.0;

	for(int i = 0; i<800; ++i){

		if(i == 0){
			avg_height = max_res[i];
			max_height = max_res[i];
			min_height = min_res[i];
			avg_diff_height = max_res[i] - min_res[i];
			max_diff_height = max_res[i] - min_res[i];
			min_diff_height = max_res[i] - min_res[i];
		}else{
			avg_height += max_res[i];
			avg_diff_height += (max_res[i] - min_res[i]);

			if(max_res[i] > max_height){
				max_height = max_res[i];
			}

			if(min_res[i] < min_height){
				min_height = min_res[i];
			}

			if((max_res[i] - min_res[i]) > max_diff_height){
				max_diff_height = max_res[i] - min_res[i];
			}

			if((max_res[i] - min_res[i]) < min_diff_height){
				min_diff_height = max_res[i] - min_res[i];	
			}
		}
	}

	avg_height 		/= 800.0;
	avg_diff_height /= 800.0;

	std::cout << "Average Height: " 			<< avg_height 	   << std::endl;
	std::cout << "Max Height: " 				<< max_height 	   << std::endl;
	std::cout << "Min Height: " 				<< min_height 	   << std::endl;
	std::cout << "Average Height Difference: "  << avg_diff_height << std::endl;
	std::cout << "Max Height Difference: " 		<< max_diff_height << std::endl;
	std::cout << "Min Height Difference: " 		<< min_diff_height << std::endl;
}
