CFLAGS=-std=c++11 -O2
LFLAGS=-lprimesieve -L.:/usr/local/include -I.

all: pb614

# Careful about the order of parameters in the below line;
# the .cc file must come first, else we got a linking issue.
%: %.cc
	g++ $^ $(CFLAGS) $(LFLAGS) -o $@

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
	@rm -rf maximix_arrangements
	@rm -rf double_pandigital_number_divisible_by_11
	@rm -rf right_triangles_with_integer_coordinates
	@rm -rf prime_connection
	@rm -rf diophantine_reciprocals
	@rm -rf non-bouncy_numbers
	@rm -rf pseudo-fortunate_numbers
	@rm -rf sliding_game
	@rm -rf swapping_counters
	@rm -rf gaussian_integers
	@rm -rf tangent_circles
	@rm -rf divisor_nim
	@rm -rf nested_square_roots
	@rm -rf pb614
	@rm -rf pb643
	@rm -rf pb351
	@rm -rf pb642
	@rm -rf pb407
	@rm -rf pb641


