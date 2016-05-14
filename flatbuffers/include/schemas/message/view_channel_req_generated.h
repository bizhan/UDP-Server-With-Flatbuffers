// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_VIEWCHANNELREQ_FBS_MSG_H_
#define FLATBUFFERS_GENERATED_VIEWCHANNELREQ_FBS_MSG_H_

#include "flatbuffers/flatbuffers.h"

namespace fbs {
struct Session;
struct GeneralResponse;
}  // namespace fbs

namespace fbs {
namespace msg {

struct ViewChannelRequest;

struct ViewChannelRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const fbs::Session *session() const { return GetPointer<const fbs::Session *>(4); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* session */) &&
           verifier.VerifyTable(session()) &&
           verifier.EndTable();
  }
};

struct ViewChannelRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_session(flatbuffers::Offset<fbs::Session> session) { fbb_.AddOffset(4, session); }
  ViewChannelRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ViewChannelRequestBuilder &operator=(const ViewChannelRequestBuilder &);
  flatbuffers::Offset<ViewChannelRequest> Finish() {
    auto o = flatbuffers::Offset<ViewChannelRequest>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<ViewChannelRequest> CreateViewChannelRequest(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<fbs::Session> session = 0) {
  ViewChannelRequestBuilder builder_(_fbb);
  builder_.add_session(session);
  return builder_.Finish();
}

inline const fbs::msg::ViewChannelRequest *GetViewChannelRequest(const void *buf) { return flatbuffers::GetRoot<fbs::msg::ViewChannelRequest>(buf); }

inline bool VerifyViewChannelRequestBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<fbs::msg::ViewChannelRequest>(); }

inline void FinishViewChannelRequestBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<fbs::msg::ViewChannelRequest> root) { fbb.Finish(root); }

}  // namespace msg
}  // namespace fbs

#endif  // FLATBUFFERS_GENERATED_VIEWCHANNELREQ_FBS_MSG_H_
