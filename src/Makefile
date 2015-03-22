CFLAGS=-std=c++11
LFLAGS=-lprimesieve -I.

all: problem_508

%: %.cc
	g++ $(CFLAGS) $(LFLAGS) -o $@ $^

.PHONY: clean

clean:
	@rm -rf coin
	@rm -rf largest_exponential
	@rm -rf path_sum_two_ways
	@rm -rf singular_integer_right_triangles
	@rm -rf path_sum_three_ways  
	@rm -rf counting_rectangles
	@rm -rf arranged_probability
	@rm -rf the_incenter_of_a_triangle
	@rm -rf bouncy_numbers
	@rm -rf concealed_square
	@rm -rf eight_divisors
	@rm -rf semiprimes
	@rm -rf bidirection
	@rm -rf idempotents
	@rm -rf palindromic_sums
	@rm -rf abc-hits
	@rm -rf dice_game
	@rm -rf digital_root_clocks
	@rm -rf problem_508
