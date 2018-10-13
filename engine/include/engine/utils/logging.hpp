/**
 *  @file logging.hpp
 *  @brief Class and #defines for the logger.
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define INITLOGGER( logFile, vbLevel ) pheonix::Logger::init( logFile, vbLevel )
#define DESTROYLOGGER() pheonix::Logger::destroy()

#define ERROR( message )    pheonix::Logger::logMessage( __FILE__, __LINE__, message, pheonix::LogVerbosity::ERROR )
#define WARNING( message )  pheonix::Logger::logMessage( __FILE__, __LINE__, message, pheonix::LogVerbosity::WARNING )
#define INFO( message )     pheonix::Logger::logMessage( __FILE__, __LINE__, message, pheonix::LogVerbosity::INFO )
#define DEBUG( message )    pheonix::Logger::logMessage( __FILE__, __LINE__, message, pheonix::LogVerbosity::DEBUG )

namespace pheonix
{
    /** @enum pheonix::LogVerbosity
     *  @brief This is what will define whether certain messages are low enough a verbosity to be outputted.
     */
    enum class LogVerbosity
    {
        ERROR = 0,      ///< ERROR -> Is for critical messages that result in FAILURES
        WARNING = 1,    ///< WARNING-> More verbose logging, for errors that are not FATAL, but are errors none-the-less
        INFO = 2,       ///< INFO -> For important information which can aid finding problems quickly
        DEBUG= 3,       ///< DEBUG-> For absolutely everything, like entering a function to exiting the function.
    };

    class Logger
    {
    public:

        /**
         * @brief Initialise the Logger, open file and set the initial logging verbosity level.
         * @param[in] logFile The file in which log messages should be outputted to, as well as the console.
         * @param[in] vbLevel The initial logging verbosity, dictates what should and shouldn't be outputted, by referring to LogVerbosity.
         */
        static void init( std::string logFile, LogVerbosity vbLevel );

        /**
         * @brief Destroy the logger, by closing the log file.
         */
        static void destroy();

        /**
         * @brief logMessage is to actually log the message to the console and the file opened by init();
         * @param[in] errorFile     The file from which the error is occurring
         * @param[in] lineNumber    The line from which the error is occurring
         * @param[in] message       The actual message to be logged.
         * @param[in] verbosity     The verbosity of the message, dictates whether the message is outputted or not.
         */
        static void logMessage( std::string errorFile, int lineNumber, std::string message, LogVerbosity verbosity);

    private:
        Logger() {}
        ~Logger() {}

        /// @brief String for the file to log to.
        static std::string m_logFile;

        /// @brief The file handle for the logging file, opened by init(), and closed by destroy().
        static std::ofstream m_logFileHandle;

        /// @brief The initial logging level that is referred to, to dictate what gets logged and what doesn't.
        static LogVerbosity m_vbLevel;

        /// @brief The lookup table for ENUM, so something can get outputted like "[ERROR]"
        static const char* LogVerbosityLookup[];
    };

} // namespace pheonix