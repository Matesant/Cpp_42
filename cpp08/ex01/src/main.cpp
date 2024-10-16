#include "Span.hpp"

void                newLine(void);
void                thatIsAllFolks();
std::vector<int>    createAndFillVector(int i) ;
void                printTag(const std::string& str);

int	main(void)
{
    Span span(5);

    printTag("Adding numbers to span");
    newLine();

    try {
        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(3);
        span.addNumber(4);
        span.addNumber(5);
        std::vector<int> numbers = span.getNumbers();
        std::vector<int>::iterator it;
        for (it = numbers.begin(); it != numbers.end(); ++it) {
            printColor(*it, GREEN);
        }
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }

    newLine();
    printTag("Finding shortest and longest span");
    newLine();

    printColor(toString("Shortest : " + toString(span.shortestSpan())), GREEN);
    printColor(toString("Longest : " + toString(span.longestSpan())), GREEN);

    newLine();
    printTag("Trying to add more numbers than span can hold");
    newLine();

    try {
        span.addNumber(6);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }

    newLine();
    printTag("Trying to find shortest span with less than 2 numbers");
    newLine();

    Span span2(1);
    try {
        span2.shortestSpan();
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }

    newLine();
    printTag("Adding numbers to span using addNumbers");
    newLine();

    Span span4(21000);
    std::vector<int> v = createAndFillVector(21000);

    try
    {
        span4.addNumbersAndFill(v.begin(), v.end());
        printColor(toString("Size : " + toString(span4.getNumbers().size())), GREEN);

    }
    catch (std::exception& e)
    {
        printColor(e.what(), RED);
    }

    newLine();
    printTag("Shortest and longest span with more than 10000 elements");

    newLine();
    printColor("Shortest : " + toString(span4.shortestSpan()), GREEN);

    newLine();
    printColor("Longest : " + toString(span4.longestSpan()), GREEN);

    newLine();
    printTag("Short and long in span with more than 10000 elements");

    Span span3(11000);
    std::srand(time(NULL)); // use current time as seed for random generator
    for (int i = 0; i < 11000; ++i) {
        span3.addNumber(std::rand() % 11000); // Limiting the random number to a range for better readability
    }

    newLine();
    printColor(toString("Shortest : " + toString(span3.shortestSpan())), GREEN);

    newLine();
    printColor(toString("Longest : " + toString(span3.longestSpan())), GREEN);
    newLine();

    newLine();
    printTag("size of span3");
    newLine();

    printColor(toString("Size : " + toString(span3.getNumbers().size())), GREEN);


    newLine();
	thatIsAllFolks();
    return 0;
}

std::vector<int> createAndFillVector(int i) 
{
	std::vector<int> v;
	std::srand(time(0));
	for (int j = 0; j < i; ++j) {
		v.push_back(std::rand() % i);
	}
	return v;
}

void	newLine(void)
{
	std::cout << std::endl;
}

void thatIsAllFolks()
{
    const char* message = "That's all folks!";
    const int delay = 100000;
    const char* colors[] = {YELLOW, GREEN, CYAN, MAGENTA, BLUE, RED};
    const int numColors = sizeof(colors) / sizeof(colors[0]);
    for (int i = 0; message[i] != '\0'; ++i)
    {
        std::cout << colors[i % numColors] << message[i] << RESET;
        std::cout.flush();
        usleep(delay);
    }
    std::cout << std::endl;
}

void printTag(const std::string& str) 
{
    const int totalWidth = 60;
    int strLength = str.length();
    if (strLength >= totalWidth) {
        std::cout << str << std::endl;
        return;
    }

	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
    int hyphensEachSide = (totalWidth - strLength) / 2;
    int extraHyphen = (totalWidth - strLength) % 2;

    std::string hyphens(hyphensEachSide, '-');
    std::cout << YELLOW << INVERSE << hyphens << str << hyphens << std::string(extraHyphen, '-') << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
}
