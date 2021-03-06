// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_GETPROFILEREQ_FBS_ACCOUNT_H_
#define FLATBUFFERS_GENERATED_GETPROFILEREQ_FBS_ACCOUNT_H_

#include "flatbuffers/flatbuffers.h"

namespace fbs {
struct Session;
struct GeneralResponse;
}  // namespace fbs

namespace fbs {
namespace account {

struct GetProfileRequest;

struct GetProfileRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const fbs::Session *session() const { return GetPointer<const fbs::Session *>(4); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* session */) &&
           verifier.VerifyTable(session()) &&
           verifier.EndTable();
  }
};

struct GetProfileRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_session(flatbuffers::Offset<fbs::Session> session) { fbb_.AddOffset(4, session); }
  GetProfileRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  GetProfileRequestBuilder &operator=(const GetProfileRequestBuilder &);
  flatbuffers::Offset<GetProfileRequest> Finish() {
    auto o = flatbuffers::Offset<GetProfileRequest>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<GetProfileRequest> CreateGetProfileRequest(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<fbs::Session> session = 0) {
  GetProfileRequestBuilder builder_(_fbb);
  builder_.add_session(session);
  return builder_.Finish();
}

inline const fbs::account::GetProfileRequest *GetGetProfileRequest(const void *buf) { return flatbuffers::GetRoot<fbs::account::GetProfileRequest>(buf); }

inline bool VerifyGetProfileRequestBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<fbs::account::GetProfileRequest>(); }

inline void FinishGetProfileRequestBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<fbs::account::GetProfileRequest> root) { fbb.Finish(root); }

}  // namespace account
}  // namespace fbs

#endif  // FLATBUFFERS_GENERATED_GETPROFILEREQ_FBS_ACCOUNT_H_
