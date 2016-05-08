// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_EDITCOMMENTREQ_FBS_POST_H_
#define FLATBUFFERS_GENERATED_EDITCOMMENTREQ_FBS_POST_H_

#include "flatbuffers/flatbuffers.h"

namespace fbs {
struct Session;
struct GeneralResponse;
}  // namespace fbs

namespace fbs {
namespace post {

struct EditCommentRequest;

struct EditCommentRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const fbs::Session *session() const { return GetPointer<const fbs::Session *>(4); }
  uint64_t post_id() const { return GetField<uint64_t>(6, 0); }
  uint64_t comment_id() const { return GetField<uint64_t>(8, 0); }
  const flatbuffers::String *content() const { return GetPointer<const flatbuffers::String *>(10); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* session */) &&
           verifier.VerifyTable(session()) &&
           VerifyField<uint64_t>(verifier, 6 /* post_id */) &&
           VerifyField<uint64_t>(verifier, 8 /* comment_id */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 10 /* content */) &&
           verifier.Verify(content()) &&
           verifier.EndTable();
  }
};

struct EditCommentRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_session(flatbuffers::Offset<fbs::Session> session) { fbb_.AddOffset(4, session); }
  void add_post_id(uint64_t post_id) { fbb_.AddElement<uint64_t>(6, post_id, 0); }
  void add_comment_id(uint64_t comment_id) { fbb_.AddElement<uint64_t>(8, comment_id, 0); }
  void add_content(flatbuffers::Offset<flatbuffers::String> content) { fbb_.AddOffset(10, content); }
  EditCommentRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  EditCommentRequestBuilder &operator=(const EditCommentRequestBuilder &);
  flatbuffers::Offset<EditCommentRequest> Finish() {
    auto o = flatbuffers::Offset<EditCommentRequest>(fbb_.EndTable(start_, 4));
    return o;
  }
};

inline flatbuffers::Offset<EditCommentRequest> CreateEditCommentRequest(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<fbs::Session> session = 0,
   uint64_t post_id = 0,
   uint64_t comment_id = 0,
   flatbuffers::Offset<flatbuffers::String> content = 0) {
  EditCommentRequestBuilder builder_(_fbb);
  builder_.add_comment_id(comment_id);
  builder_.add_post_id(post_id);
  builder_.add_content(content);
  builder_.add_session(session);
  return builder_.Finish();
}

inline const fbs::post::EditCommentRequest *GetEditCommentRequest(const void *buf) { return flatbuffers::GetRoot<fbs::post::EditCommentRequest>(buf); }

inline bool VerifyEditCommentRequestBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<fbs::post::EditCommentRequest>(); }

inline void FinishEditCommentRequestBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<fbs::post::EditCommentRequest> root) { fbb.Finish(root); }

}  // namespace post
}  // namespace fbs

#endif  // FLATBUFFERS_GENERATED_EDITCOMMENTREQ_FBS_POST_H_