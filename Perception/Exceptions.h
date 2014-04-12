/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <sstream>
#include <stdexcept>

namespace perception
{

class _PerceptionError : public std::runtime_error
{
public:
    template<typename ExceptionT>
    static void raiseError(const std::string& errorMessage, const std::string& details = "")
    {
        std::stringstream msg;
        msg << errorMessage;

        if (!details.empty())
        {
            msg << ": " << details;
        }

        throw ExceptionT(msg.str());
    }

protected:
    explicit _PerceptionError(const std::string& errorMessage)
        : std::runtime_error(errorMessage)
    {}
};


class DataNotFoundError : public _PerceptionError
{
public:
    explicit DataNotFoundError(const std::string& errorMessage)
        : _PerceptionError(errorMessage)
    {}
};


class IllegalParameterError : public _PerceptionError
{
public:
    explicit IllegalParameterError(const std::string& errorMessage)
        : _PerceptionError(errorMessage)
    {}
};


class NetworkError : public _PerceptionError
{
public:
    explicit NetworkError(const std::string& errorMessage)
        : _PerceptionError(errorMessage)
    {}
};

} /* namespace perception */

#endif /* EXCEPTIONS_H_ */
