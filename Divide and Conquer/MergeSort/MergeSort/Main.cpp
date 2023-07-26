#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
	std::vector<int> output = {};

	int i = 0;
	int j = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j]) {
			output.push_back(left[i]);
			i++;
		}
		else {
			output.push_back(right[j]);
			j++;
		}
	}

	output.insert(output.end(), left.begin() + i, left.end());
	output.insert(output.end(), right.begin() + j, right.end());

	return output;
}

std::vector<int> split_array(std::vector<int>& input) {
	if (input.size() == 1) {
		return input;
	}

	std::vector<int> first_half(input.begin(), input.begin() + input.size() / 2);
	std::vector<int> second_half(input.begin() + input.size() / 2, input.end());

	std::vector<int> left = split_array(first_half);
	std::vector<int> right = split_array(second_half);

	return merge(left, right);
}

int main() {
	std::vector<int> in = { 1, 2, 3, 4, 5, 32, 6, 7, 8, 432, 324, 6 };

	std::vector<int> result = split_array(in);

	for (const auto& elem : result) {
		std::cout << elem << ' ';
	}

	std::cout << std::endl;
}