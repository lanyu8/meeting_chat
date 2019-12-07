#include "thread_manager.h"
#include <memory>
#include <mutex>

namespace vi {
	ThreadManager::ThreadManager()
	{
	}

	ThreadManager::~ThreadManager()
	{
	}

	void ThreadManager::init() 
	{
		std::lock_guard<std::mutex> lock(_mutex);
		_mainThread = rtc::ThreadManager::Instance()->CurrentThread();

		_threadsMap[ThreadName::WORKER] = rtc::Thread::Create();
		_threadsMap[ThreadName::WORKER]->SetName("vi::WORKER", nullptr);

		_threadsMap[ThreadName::WEBRTC_SERVICE] = rtc::Thread::Create();
		_threadsMap[ThreadName::WEBRTC_SERVICE]->SetName("vi::WEBRTC_SERVICE", nullptr);

		_threadsMap[ThreadName::VIDEO_ROOM] = rtc::Thread::Create();
		_threadsMap[ThreadName::VIDEO_ROOM]->SetName("vi::VIDEO_ROOM", nullptr);

		for (const auto& thread : _threadsMap) {
			thread.second->Start();
		}
	}

	rtc::Thread* ThreadManager::getThread(ThreadName name) 
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (ThreadName::MAIN == name) {
			return _mainThread;
		} else if (_threadsMap.find(name) != _threadsMap.end()) {
			return _threadsMap[name].get();
		}

		return nullptr;
	}
}