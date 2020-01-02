#include "MessageQueue.h"

MessageQueue::MessageQueue(int maximalMessageCount, float messageLifetime):_maximalMessageCount(maximalMessageCount),
                                                                           _messageLifetime(messageLifetime)
{ }

void MessageQueue::addNewMessage(const std::string& message) {
    if(getCurrentMessageCount() >= getMaximalMessageCount())
        popFrontMessage();

    _messages.push_back(message);
}

void MessageQueue::popFrontMessage() {
    _messages.pop_front();
}

void MessageQueue::popBackMessage() {
    _messages.pop_back();
}

void MessageQueue::clear() {
    _messages.clear();
}

void MessageQueue::setMaximalMessageCount(int count) {
    _maximalMessageCount = count;
}

std::string& MessageQueue::operator[](int index) {
    return _messages[index];
}

const std::string& MessageQueue::operator[](int index) const {
    return _messages[index];
}

std::string MessageQueue::generateMessageLabel(const std::string& separator) const {
    std::string result = "";
    for(int i = 0;i < getCurrentMessageCount(); ++i) {
        result += operator[](i) + separator;
    }
    return result;
}
