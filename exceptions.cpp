class customException {
    private:
        std::string mMessage;
    public:
        customException(std::string msg) {
            mMessage = "\n";
            mMessage.append("\033[4;31m");    // red underline
            mMessage.append("Error");         // error title
            mMessage.append("\033[0m");       // reset formatting
            mMessage.append(": ");            //
            mMessage.append("\033[1;37m");    // bold white
            mMessage.append(msg);             // error message
            mMessage.append("\033[0m");       // reset formatting
        }
        std::string message() {
            return mMessage;
        }
};

class badFileException : public customException {
    public:
        badFileException(std::string msg) : customException (msg) {
        }
};