// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_VIEWCHANNELRESP_FBS_MSG_H_
#define FLATBUFFERS_GENERATED_VIEWCHANNELRESP_FBS_MSG_H_

#include "flatbuffers/flatbuffers.h"

namespace fbs {
struct Session;
struct GeneralResponse;
}  // namespace fbs
namespace fbs {
namespace msg {
struct FileChunk;
struct StringContent;
struct MsgEntity;
struct ChannelEntity;
}  // namespace msg
}  // namespace fbs

namespace fbs {
namespace msg {

struct ViewChannelResponse;

struct ViewChannelResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  fbs::Status status_code() const { return static_cast<fbs::Status>(GetField<int8_t>(4, 0)); }
  const fbs::Session *session() const { return GetPointer<const fbs::Session *>(6); }
  const flatbuffers::Vector<flatbuffers::Offset<fbs::msg::ChannelEntity>> *channels() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<fbs::msg::ChannelEntity>> *>(8); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, 4 /* status_code */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* session */) &&
           verifier.VerifyTable(session()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* channels */) &&
           verifier.Verify(channels()) &&
           verifier.VerifyVectorOfTables(channels()) &&
           verifier.EndTable();
  }
};

struct ViewChannelResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status_code(fbs::Status status_code) { fbb_.AddElement<int8_t>(4, static_cast<int8_t>(status_code), 0); }
  void add_session(flatbuffers::Offset<fbs::Session> session) { fbb_.AddOffset(6, session); }
  void add_channels(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<fbs::msg::ChannelEntity>>> channels) { fbb_.AddOffset(8, channels); }
  ViewChannelResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ViewChannelResponseBuilder &operator=(const ViewChannelResponseBuilder &);
  flatbuffers::Offset<ViewChannelResponse> Finish() {
    auto o = flatbuffers::Offset<ViewChannelResponse>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<ViewChannelResponse> CreateViewChannelResponse(flatbuffers::FlatBufferBuilder &_fbb,
   fbs::Status status_code = fbs::Status_OK,
   flatbuffers::Offset<fbs::Session> session = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<fbs::msg::ChannelEntity>>> channels = 0) {
  ViewChannelResponseBuilder builder_(_fbb);
  builder_.add_channels(channels);
  builder_.add_session(session);
  builder_.add_status_code(status_code);
  return builder_.Finish();
}

inline const fbs::msg::ViewChannelResponse *GetViewChannelResponse(const void *buf) { return flatbuffers::GetRoot<fbs::msg::ViewChannelResponse>(buf); }

inline bool VerifyViewChannelResponseBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<fbs::msg::ViewChannelResponse>(); }

inline void FinishViewChannelResponseBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<fbs::msg::ViewChannelResponse> root) { fbb.Finish(root); }

}  // namespace msg
}  // namespace fbs

#endif  // FLATBUFFERS_GENERATED_VIEWCHANNELRESP_FBS_MSG_H_
