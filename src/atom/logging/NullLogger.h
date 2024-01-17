#pragma once
#include "atom/logging/Logger.h"

namespace Atom::Logging
{
    /// --------------------------------------------------------------------------------------------
    /// NullLogger is used in cases where it's not appropriate to return nullptr.
    ///
    /// NullLogger is stateless and doesn't do anything except refusing every log request.
    /// Damn rude nigga!.
    /// --------------------------------------------------------------------------------------------
    class NullLogger final: public Logger
    {
    public:
        /// ----------------------------------------------------------------------------------------
        /// Default constructs NullLogger.
        /// ----------------------------------------------------------------------------------------
        constexpr NullLogger() {}

    public:
        /// ----------------------------------------------------------------------------------------
        /// Returns name of the NullLogger.
        /// ----------------------------------------------------------------------------------------
        constexpr virtual auto Name() const -> StringView override
        {
            return _Name;
        }

        /// ----------------------------------------------------------------------------------------
        /// Does nothing.
        /// ----------------------------------------------------------------------------------------
        constexpr virtual auto Log(LogMsg& logMsg) -> void override {}

        /// ----------------------------------------------------------------------------------------
        /// Does nothing.
        /// ----------------------------------------------------------------------------------------
        constexpr virtual auto Flush() -> void override {}

        /// ----------------------------------------------------------------------------------------
        /// Always returns false to avoid constructing log msg.
        /// ----------------------------------------------------------------------------------------
        constexpr virtual auto CheckLogLevel(ELogLevel lvl) const -> bool override
        {
            return false;
        }

    public:
        /// ----------------------------------------------------------------------------------------
        /// Static instance of this type because this type is stateless.
        /// It's recommended to use this instead of creating one each time.
        /// ----------------------------------------------------------------------------------------
        static LoggerPtr Instance;

    private:
        /// ----------------------------------------------------------------------------------------
        /// Name of the NullLogger.
        /// ----------------------------------------------------------------------------------------
        static const StringView _Name;
    };

    inline LoggerPtr NullLogger::Instance = MakeShared<NullLogger>();
    inline const StringView NullLogger::_Name = MakeRange("NullLogger");
}
