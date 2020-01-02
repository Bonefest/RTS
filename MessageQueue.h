#ifndef MESSAGEQUEUE_H_INCLUDED
#define MESSAGEQUEUE_H_INCLUDED

#include <deque>
#include <string>

class MessageQueue {
public:
    MessageQueue(int maximalMessageCount = 100, float messageLifetime = -1.0f);
    void addNewMessage(const std::string& message);
    void popFrontMessage();
    void popBackMessage();
    void clear();

    void setMaximalMessageCount(int count);
    inline int getMaximalMessageCount() const { return _maximalMessageCount; }

    inline int getCurrentMessageCount() const { return _messages.size(); }

    std::string& operator[](int index);
    const std::string& operator[](int index) const;

    std::string generateMessageLabel(const std::string& separator = "\n") const;

private:
    std::deque<std::string> _messages;
    int _maximalMessageCount;
    float _messageLifetime;
};

#endif // MESSAGEQUEUE_H_INCLUDED
