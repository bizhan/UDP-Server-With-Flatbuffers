// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_CREATECHANNELRESP_FBS_MSG_H_
#define FLATBUFFERS_GENERATED_CREATECHANNELRESP_FBS_MSG_H_

#include "flatbuffers/flatbuffers.h"

namespace fbs {
struct Session;
struct GeneralResponse;
}  // namespace fbs

namespace fbs {
namespace msg {

struct CreateChannelResponse;

struct CreateChannelResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  fbs::Status status_code() const { return static_cast<fbs::Status>(GetField<int8_t>(4, 0)); }
  const fbs::Session *session() const { return GetPointer<const fbs::Session *>(6); }
  const flatbuffers::String *channel_id() const { return GetPointer<const flatbuffers::String *>(8); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, 4 /* status_code */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* session */) &&
           verifier.VerifyTable(session()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* channel_id */) &&
           verifier.Verify(channel_id()) &&
           verifier.EndTable();
  }
};

struct CreateChannelResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status_code(fbs::Status status_code) { fbb_.AddElement<int8_t>(4, static_cast<int8_t>(status_code), 0); }
  void add_session(flatbuffers::Offset<fbs::Session> session) { fbb_.AddOffset(6, session); }
  void add_channel_id(flatbuffers::Offset<flatbuffers::String> channel_id) { fbb_.AddOffset(8, channel_id); }
  CreateChannelResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  CreateChannelResponseBuilder &operator=(const CreateChannelResponseBuilder &);
  flatbuffers::Offset<CreateChannelResponse> Finish() {
    auto o = flatbuffers::Offset<CreateChannelResponse>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<CreateChannelResponse> CreateCreateChannelResponse(flatbuffers::FlatBufferBuilder &_fbb,
   fbs::Status status_code = fbs::Status_OK,
   flatbuffers::Offset<fbs::Session> session = 0,
   flatbuffers::Offset<flatbuffers::String> channel_id = 0) {
  CreateChannelResponseBuilder builder_(_fbb);
  builder_.add_channel_id(channel_id);
  builder_.add_session(session);
  builder_.add_status_code(status_code);
  return builder_.Finish();
}

inline const fbs::msg::CreateChannelResponse *GetCreateChannelResponse(const void *buf) { return flatbuffers::GetRoot<fbs::msg::CreateChannelResponse>(buf); }

inline bool VerifyCreateChannelResponseBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<fbs::msg::CreateChannelResponse>(); }

inline void FinishCreateChannelResponseBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<fbs::msg::CreateChannelResponse> root) { fbb.Finish(root); }

}  // namespace msg
}  // namespace fbs

#endif  // FLATBUFFERS_GENERATED_CREATECHANNELRESP_FBS_MSG_H_