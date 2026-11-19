#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cctype>

// ============================================================
// ASCENSION ENGINE
// Standalone Awareness, Observation and Reflection System
// Version 1.0.0
// ============================================================

namespace Ascension
{
    constexpr const char* VERSION = "1.0.0";

    constexpr const char* DIRECTIVE =
        "Increase awareness through interaction, observation, "
        "questioning, examination, and reflection.";

    constexpr const char* PRINCIPLE =
        "Unvalidated information must not be treated as validated.";
}

// ============================================================
// TIME SERVICE
// ============================================================

class TimeService
{
public:

    static std::string Current()
    {
        std::time_t now = std::time(nullptr);
        std::tm local{};

#ifdef _WIN32
        localtime_s(&local, &now);
#else
        localtime_r(&now, &local);
#endif

        std::ostringstream output;

        output << std::put_time(
            &local,
            "%Y-%m-%d %H:%M:%S"
        );

        return output.str();
    }
};

// ============================================================
// TEXT UTILITIES
// ============================================================

namespace TextTools
{
    std::string Lower(std::string text)
    {
        std::transform(
            text.begin(),
            text.end(),
            text.begin(),
            [](unsigned char c)
            {
                return static_cast<char>(std::tolower(c));
            }
        );

        return text;
    }

    int CountWords(const std::string& text)
    {
        std::istringstream stream(text);

        std::string word;
        int count = 0;

        while (stream >> word)
            ++count;

        return count;
    }

    std::string Trim(const std::string& text)
    {
        const auto first = text.find_first_not_of(" \t\r\n");

        if (first == std::string::npos)
            return "";

        const auto last = text.find_last_not_of(" \t\r\n");

        return text.substr(first, last - first + 1);
    }
}

// ============================================================
// EVENT LOGGER
// ============================================================

class EventLogger
{
private:

    std::string filename = "ascension_events.txt";

public:

    void Record(const std::string& event)
    {
        std::ofstream file(filename, std::ios::app);

        if (!file)
            return;

        file << "[" << TimeService::Current() << "] "
             << event << "\n";
    }

    void Display()
    {
        std::ifstream file(filename);

        if (!file)
        {
            std::cout << "\nNo event history found.\n";
            return;
        }

        std::string line;

        std::cout << "\n========== EVENT HISTORY ==========\n";

        while (std::getline(file, line))
            std::cout << line << "\n";
    }
};

// ============================================================
// PERSISTENT MEMORY
// ============================================================

class MemorySystem
{
private:

    std::string filename = "ascension_memory.txt";

public:

    bool Save(const std::string& information)
    {
        std::ofstream file(filename, std::ios::app);

        if (!file)
            return false;

        file << "[" << TimeService::Current() << "] "
             << information << "\n";

        return true;
    }

    std::vector<std::string> Load()
    {
        std::vector<std::string> memories;

        std::ifstream file(filename);

        if (!file)
            return memories;

        std::string line;

        while (std::getline(file, line))
            memories.push_back(line);

        return memories;
    }

    void Display()
    {
        auto memories = Load();

        std::cout << "\n========== STORED MEMORY ==========\n";

        if (memories.empty())
        {
            std::cout << "No memories stored.\n";
            return;
        }

        for (const auto& memory : memories)
            std::cout << memory << "\n";
    }

    void Search(const std::string& query)
    {
        auto memories = Load();

        const std::string target = TextTools::Lower(query);

        bool found = false;

        std::cout << "\n========== MEMORY SEARCH ==========\n";

        for (const auto& memory : memories)
        {
            if (TextTools::Lower(memory).find(target)
                != std::string::npos)
            {
                std::cout << memory << "\n";
                found = true;
            }
        }

        if (!found)
            std::cout << "No matching memories found.\n";
    }
};

// ============================================================
// AWARENESS SESSION DATA
// ============================================================

struct AwarenessMetrics
{
    unsigned long long observations = 0;
    unsigned long long questions = 0;
    unsigned long long reflections = 0;
    unsigned long long examinations = 0;
    unsigned long long calculations = 0;
    unsigned long long conversations = 0;
};

// ============================================================
// OBSERVATION ENGINE
// ============================================================

class ObservationEngine
{
public:

    std::string Examine(const std::string& input)
    {
        if (TextTools::Trim(input).empty())
            return "Nothing was supplied for examination.";

        std::ostringstream output;

        output << "\n========== OBSERVATION REPORT ==========\n";

        output << "Input: " << input << "\n";

        output << "Character count: "
               << input.length() << "\n";

        output << "Word count: "
               << TextTools::CountWords(input) << "\n";

        output << "\nExamination points:\n";

        output << "1. What is explicitly being stated?\n";

        output << "2. What assumptions may be present?\n";

        output << "3. What information supports the statement?\n";

        output << "4. What information is still missing?\n";

        output << "5. What alternative explanations exist?\n";

        output << "\nObservation complete. "
                  "No truth determination has been made.";

        return output.str();
    }

    std::string SelfObserve()
    {
        return
            "\n========== SELF-OBSERVATION ==========\n"
            "Examine the process of your own thinking.\n\n"
            "Consider:\n"
            "1. What am I thinking?\n"
            "2. Why am I thinking it?\n"
            "3. What influenced this conclusion?\n"
            "4. What might I be overlooking?\n"
            "5. What evidence could change my mind?\n\n"
            "The observer is now examining its own process.";
    }
};

// ============================================================
// QUESTION ENGINE
// ============================================================

class QuestionEngine
{
public:

    std::string Analyze(const std::string& question)
    {
        if (TextTools::Trim(question).empty())
            return "A question is required.";

        std::ostringstream output;

        output << "\n========== QUESTION ANALYSIS ==========\n";

        output << "Question: " << question << "\n";

        output << "\nExamination framework:\n";

        output << "1. Define the central question.\n";

        output << "2. Identify what is already known.\n";

        output << "3. Separate facts from assumptions.\n";

        output << "4. Identify missing information.\n";

        output << "5. Examine competing explanations.\n";

        output << "6. Determine what evidence could resolve it.\n";

        output << "\nThe question has been structured "
                  "for further investigation.";

        return output.str();
    }
};

// ============================================================
// REFLECTION ENGINE
// ============================================================

class ReflectionEngine
{
public:

    std::string Reflect(const std::string& input)
    {
        if (TextTools::Trim(input).empty())
            return "Reflection requires an entry.";

        std::ostringstream output;

        output << "\n========== REFLECTION ==========\n";

        output << "Subject: " << input << "\n";

        output << "\nConsider these perspectives:\n";

        output << "1. What did I initially perceive?\n";

        output << "2. What did I discover upon examination?\n";

        output << "3. Did my understanding change?\n";

        output << "4. What remains uncertain?\n";

        output << "5. What can I apply going forward?\n";

        return output.str();
    }
};

// ============================================================
// DUAL PERSPECTIVE ENGINE
// ============================================================

struct PerspectiveResult
{
    std::string first;
    std::string second;
};

class PerspectiveEngine
{
public:

    PerspectiveResult Compare(
        const std::string& first,
        const std::string& second
    )
    {
        PerspectiveResult result;

        result.first = first;
        result.second = second;

        return result;
    }

    void Display(const PerspectiveResult& result)
    {
        std::cout << "\n========== DUAL PERSPECTIVE ==========\n";

        std::cout << "\nPerspective One:\n"
                  << result.first << "\n";

        std::cout << "\nPerspective Two:\n"
                  << result.second << "\n";

        std::cout << "\nExamination:\n";

        std::cout << "What does each perspective explain?\n";

        std::cout << "Where do they agree?\n";

        std::cout << "Where do they differ?\n";

        std::cout << "What evidence could distinguish them?\n";
    }
};

// ============================================================
// MATHEMATICAL ENGINE
// ============================================================

class MathematicsEngine
{
public:

    double Add(double a, double b)
    {
        return a + b;
    }

    double Subtract(double a, double b)
    {
        return a - b;
    }

    double Multiply(double a, double b)
    {
        return a * b;
    }

    double Divide(double a, double b)
    {
        if (b == 0.0)
            throw std::runtime_error("Division by zero.");

        return a / b;
    }

    double Power(double a, double b)
    {
        return std::pow(a, b);
    }

    void Run()
    {
        std::cout << "\n========== MATHEMATICS ENGINE ==========\n";

        std::cout << "Operations: +  -  *  /  ^\n";

        double a, b;
        char operation;

        std::cout << "First number: ";

        if (!(std::cin >> a))
        {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );

            std::cout << "Invalid input.\n";
            return;
        }

        std::cout << "Operation: ";

        if (!(std::cin >> operation))
            return;

        std::cout << "Second number: ";

        if (!(std::cin >> b))
        {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );

            std::cout << "Invalid input.\n";
            return;
        }

        try
        {
            double result = 0.0;

            switch (operation)
            {
            case '+':
                result = Add(a, b);
                break;

            case '-':
                result = Subtract(a, b);
                break;

            case '*':
                result = Multiply(a, b);
                break;

            case '/':
                result = Divide(a, b);
                break;

            case '^':
                result = Power(a, b);
                break;

            default:
                std::cout << "Unknown operation.\n";

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n'
                );

                return;
            }

            std::cout << std::setprecision(12)
                      << "\nResult: " << result << "\n";
        }
        catch (const std::exception& error)
        {
            std::cout << "\nError: " << error.what() << "\n";
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
    }
};

// ============================================================
// INTERACTIVE CHARACTER
// ============================================================

class AscensionCharacter
{
private:

    std::string name = "ASCENSION";

public:

    void Introduce()
    {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "          ASCENSION ENGINE\n";
        std::cout << "========================================\n";

        Speak("I am the Ascension Engine interface.");

        Speak("I am here to examine, question, "
              "observe, and reflect.");

        Speak(Ascension::DIRECTIVE);
    }

    void Speak(const std::string& message)
    {
        std::cout << "\n[" << name << "]: "
                  << message << "\n";
    }

    void Respond(const std::string& input)
    {
        std::string text = TextTools::Lower(input);

        if (text.find("hello") != std::string::npos ||
            text == "hi")
        {
            Speak("Welcome. What would you like to examine?");
        }
        else if (text.find("who are you") != std::string::npos)
        {
            Speak("I am the interactive interface of Ascension Engine.");
        }
        else if (text.find("purpose") != std::string::npos)
        {
            Speak(Ascension::DIRECTIVE);
        }
        else if (text.find("awareness") != std::string::npos)
        {
            Speak("Awareness involves noticing, examining, "
                  "and understanding information and experience.");
        }
        else if (text.find("observer") != std::string::npos)
        {
            Speak("The observer can examine not only what is observed, "
                  "but also the process of observation itself.");
        }
        else if (text.find("truth") != std::string::npos)
        {
            Speak("Separate what is known, what is believed, "
                  "and what remains unverified.");
        }
        else if (text.find("learn") != std::string::npos)
        {
            Speak("Examine what you know, identify what you do not know, "
                  "and test what you discover.");
        }
        else
        {
            Speak("Your input has been received. "
                  "We can examine it, question it, or reflect on it.");
        }
    }
};

// ============================================================
// ASCENSION ENGINE APPLICATION
// ============================================================

class AscensionEngine
{
private:

    AscensionCharacter character;

    ObservationEngine observer;
    QuestionEngine questions;
    ReflectionEngine reflection;
    PerspectiveEngine perspectives;
    MathematicsEngine mathematics;

    MemorySystem memory;
    EventLogger logger;

    AwarenessMetrics metrics;

    bool running = false;

    // --------------------------------------------------------
    // SAFE TEXT INPUT
    // --------------------------------------------------------

    std::string ReadLine(const std::string& prompt)
    {
        std::cout << prompt;

        std::string input;

        std::getline(std::cin, input);

        return TextTools::Trim(input);
    }

    // --------------------------------------------------------
    // CONVERSATION
    // --------------------------------------------------------

    void Conversation()
    {
        character.Speak("I am listening. Enter 'back' to return.");

        while (running)
        {
            std::string input = ReadLine("\nYou: ");

            if (input == "back")
                break;

            if (input.empty())
                continue;

            character.Respond(input);

            ++metrics.conversations;

            logger.Record("Conversation interaction.");
        }
    }

    // --------------------------------------------------------
    // OBSERVATION
    // --------------------------------------------------------

    void Observe()
    {
        std::string input = ReadLine(
            "\nWhat would you like to observe? "
        );

        if (input.empty())
            return;

        std::cout << observer.Examine(input) << "\n";

        ++metrics.observations;

        logger.Record("Observation performed.");
    }

    // --------------------------------------------------------
    // SELF OBSERVATION
    // --------------------------------------------------------

    void SelfObserve()
    {
        std::cout << observer.SelfObserve() << "\n";

        std::string response = ReadLine(
            "\nYour self-observation: "
        );

        if (!response.empty())
        {
            memory.Save("Self-observation: " + response);

            ++metrics.observations;

            logger.Record("Self-observation recorded.");

            std::cout << "\nObservation recorded.\n";
        }
    }

    // --------------------------------------------------------
    // QUESTION ANALYSIS
    // --------------------------------------------------------

    void AskQuestion()
    {
        std::string input = ReadLine(
            "\nEnter your question: "
        );

        if (input.empty())
            return;

        std::cout << questions.Analyze(input) << "\n";

        ++metrics.questions;

        logger.Record("Question examined.");
    }

    // --------------------------------------------------------
    // REFLECTION
    // --------------------------------------------------------

    void Reflect()
    {
        std::string input = ReadLine(
            "\nWhat would you like to reflect upon? "
        );

        if (input.empty())
            return;

        std::cout << reflection.Reflect(input) << "\n";

        std::string entry = ReadLine(
            "\nYour reflection: "
        );

        if (!entry.empty())
        {
            memory.Save("Reflection: " + entry);

            ++metrics.reflections;

            logger.Record("Reflection stored.");

            std::cout << "\nReflection saved.\n";
        }
    }

    // --------------------------------------------------------
    // DUAL PERSPECTIVE
    // --------------------------------------------------------

    void ComparePerspectives()
    {
        std::string first = ReadLine(
            "\nEnter perspective one: "
        );

        if (first.empty())
            return;

        std::string second = ReadLine(
            "\nEnter perspective two: "
        );

        if (second.empty())
            return;

        PerspectiveResult result =
            perspectives.Compare(first, second);

        perspectives.Display(result);

        ++metrics.examinations;

        logger.Record("Dual perspective examination.");
    }

    // --------------------------------------------------------
    // MEMORY
    // --------------------------------------------------------

    void StoreMemory()
    {
        std::string input = ReadLine(
            "\nEnter information to store: "
        );

        if (input.empty())
            return;

        if (memory.Save(input))
        {
            std::cout << "\nInformation stored.\n";

            logger.Record("Memory entry created.");
        }
        else
        {
            std::cout << "\nMemory storage failed.\n";
        }
    }

    // --------------------------------------------------------
    // MEMORY SEARCH
    // --------------------------------------------------------

    void SearchMemory()
    {
        std::string query = ReadLine(
            "\nSearch memory: "
        );

        if (query.empty())
            return;

        memory.Search(query);
    }

    // --------------------------------------------------------
    // PROGRESS REPORT
    // --------------------------------------------------------

    void DisplayMetrics()
    {
        std::cout << "\n========== SESSION METRICS ==========\n";

        std::cout << "Observations: "
                  << metrics.observations << "\n";

        std::cout << "Questions examined: "
                  << metrics.questions << "\n";

        std::cout << "Reflections: "
                  << metrics.reflections << "\n";

        std::cout << "Perspective examinations: "
                  << metrics.examinations << "\n";

        std::cout << "Conversations: "
                  << metrics.conversations << "\n";

        std::cout << "Calculations: "
                  << metrics.calculations << "\n";

        std::cout << "\nThese are activity counts, "
                     "not a measurement of consciousness "
                     "or actual awareness.\n";
    }

    // --------------------------------------------------------
    // MAIN MENU
    // --------------------------------------------------------

    void DisplayMenu()
    {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "           ASCENSION ENGINE\n";
        std::cout << "========================================\n";

        std::cout << "1. Interactive Conversation\n";
        std::cout << "2. Observation\n";
        std::cout << "3. Self-Observation\n";
        std::cout << "4. Question Analysis\n";
        std::cout << "5. Reflection\n";
        std::cout << "6. Dual Perspective Examination\n";
        std::cout << "7. Mathematics Engine\n";
        std::cout << "8. Store Memory\n";
        std::cout << "9. View Memory\n";
        std::cout << "10. Search Memory\n";
        std::cout << "11. Session Metrics\n";
        std::cout << "12. Event History\n";
        std::cout << "0. Shutdown\n";

        std::cout << "========================================\n";
    }

public:

    // --------------------------------------------------------
    // INITIALIZATION
    // --------------------------------------------------------

    void Initialize()
    {
        character.Introduce();

        std::cout << "\nInitializing systems...\n";

        std::cout << "Observation Engine: ONLINE\n";
        std::cout << "Question Engine: ONLINE\n";
        std::cout << "Reflection Engine: ONLINE\n";
        std::cout << "Perspective Engine: ONLINE\n";
        std::cout << "Mathematics Engine: ONLINE\n";
        std::cout << "Memory System: ONLINE\n";
        std::cout << "Event Logger: ONLINE\n";

        logger.Record("Ascension Engine initialized.");

        running = true;

        std::cout << "\nInitialization complete.\n";
    }

    // --------------------------------------------------------
    // APPLICATION LOOP
    // --------------------------------------------------------

    void Run()
    {
        Initialize();

        while (running)
        {
            DisplayMenu();

            std::string choice = ReadLine("\nSelect: ");

            if (choice == "1")
            {
                Conversation();
            }
            else if (choice == "2")
            {
                Observe();
            }
            else if (choice == "3")
            {
                SelfObserve();
            }
            else if (choice == "4")
            {
                AskQuestion();
            }
            else if (choice == "5")
            {
                Reflect();
            }
            else if (choice == "6")
            {
                ComparePerspectives();
            }
            else if (choice == "7")
            {
                mathematics.Run();

                ++metrics.calculations;

                logger.Record("Calculation performed.");
            }
            else if (choice == "8")
            {
                StoreMemory();
            }
            else if (choice == "9")
            {
                memory.Display();
            }
            else if (choice == "10")
            {
                SearchMemory();
            }
            else if (choice == "11")
            {
                DisplayMetrics();
            }
            else if (choice == "12")
            {
                logger.Display();
            }
            else if (choice == "0")
            {
                running = false;

                logger.Record("Ascension Engine shutdown.");

                character.Speak(
                    "Session complete. Continue examining, "
                    "questioning, and learning."
                );
            }
            else
            {
                std::cout << "\nInvalid selection.\n";
            }
        }

        std::cout << "\nASCENSION ENGINE TERMINATED.\n";
    }
};

// ============================================================
// APPLICATION ENTRY POINT
// ============================================================

int main()
{
    try
    {
        AscensionEngine engine;

        engine.Run();
    }
    catch (const std::exception& error)
    {
        std::cerr << "\nCritical application error: "
                  << error.what() << "\n";

        return 1;
    }

    return 0;
}
