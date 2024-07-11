#include <fstream>
#include <iostream>
#include <chrono>
#include <functional>
// file input
#include <string>


// Time tracking function
template <typename Callable>
void track_time(Callable&& func) {
    // Record the start time
    auto start = std::chrono::high_resolution_clock::now();

    // Execute the function
    func();

    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> elapsed = end - start;

    // Output the elapsed time
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}


// Example function to benchmark
void example_function() {
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf) {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return;
    }

    // We'll write two lines into this file
       outf << "Hello world...";
}



void example_function2(const std::string& data) {
    // Create or open the file Sample2.txt
    std::ofstream outf{ "Sample2.txt" };

    // Check if the file stream was opened successfully
    if (!outf) {
        std::cerr << "Uh oh, Sample2.txt could not be opened for writing!\n";
        return;  // Exit the function if the file couldn't be opened
    }

    // Write the provided data to the file
    outf << data;
}

int file_input(){
    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    // std::string strInput{};
    // while (inf >> strInput)
    //     std::cout << strInput << '\n';

      // While there's still stuff left to read
    std::string strInput{};
    while (std::getline(inf, strInput))
	std::cout << strInput << '\n';

    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}


int main() {
    std::cout << "Benchmarking Approach 1:\n";
    track_time(example_function);
 
 // Data to write to the file
    std::string data = "Yo ness... wya?";

    // Use track_time to measure the execution time of example_function2
    track_time([&]() {
        example_function2(data);
    });


    std::cout << "Benchmarking file input:\n";
    track_time(file_input);

    return 0;
}