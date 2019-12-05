#pragma once

#include <memory>
#include <functional>
#include "callback_handlers.h"
#include "Service/abstract_biz_service.h"
#include "Service/i_unified_factory.h"
#include "i_webrtc_service_listener.h"

namespace vi {
	class IWebRTCEventHandler;
	using namespace core;
	class WebRTCServiceInterface
	{
	public:
		virtual ~WebRTCServiceInterface() {}

		virtual void init() = 0;

		virtual void cleanup() = 0;

		virtual void addListener(std::shared_ptr<IWebRTCServiceListener> listener) = 0;

		virtual void removeListener(std::shared_ptr<IWebRTCServiceListener> listener) = 0;

		virtual ServiceStauts status() = 0;

		virtual void attach(const std::string& plugin, const std::string& opaqueId, std::shared_ptr<IWebRTCEventHandler> wreh) = 0;

		virtual void destroy(std::shared_ptr<DestroySessionHandler> handler) = 0;

		virtual void reconnect() = 0;

		virtual int32_t getRemoteVolume(int64_t handleId) = 0;

		virtual int32_t getLocalVolume(int64_t handleId) = 0;

		virtual bool isAudioMuted(int64_t handleId) = 0;

		virtual bool isVideoMuted(int64_t handleId) = 0;

		virtual bool muteAudio(int64_t handleId) = 0;

		virtual bool muteVideo(int64_t handleId) = 0;

		virtual bool unmuteAudio(int64_t handleId) = 0;

		virtual bool unmuteVideo(int64_t handleId) = 0;

		virtual std::string getBitrate(int64_t handleId) = 0;

		virtual void sendMessage(int64_t handleId, std::shared_ptr<SendMessageHandler> handler) = 0;

		virtual void sendData(int64_t handleId, std::shared_ptr<SendDataHandler> handler) = 0;

		virtual void sendDtmf(int64_t handleId, std::shared_ptr<SendDtmfHandler> handler) = 0;

		virtual void createOffer(int64_t handleId, std::shared_ptr<PrepareWebRTCHandler> handler) = 0;

		virtual void createAnswer(int64_t handleId, std::shared_ptr<PrepareWebRTCHandler> handler) = 0;

		virtual void handleRemoteJsep(int64_t handleId, std::shared_ptr<PrepareWebRTCPeerHandler> handler) = 0;

		virtual void hangup(int64_t handleId, bool sendRequest) = 0;

		virtual void detach(int64_t handleId, std::shared_ptr<DetachHandler> handler) = 0;
	};
}