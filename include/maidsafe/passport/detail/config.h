/***************************************************************************************************
 *  Copyright 2012 maidsafe.net limited                                                            *
 *                                                                                                 *
 *  The following source code is property of MaidSafe.net limited and is not meant for external    *
 *  use. The use of this code is governed by the licence file licence.txt found in the root of     *
 *  this directory and also on www.maidsafe.net.                                                   *
 *                                                                                                 *
 *  You are not free to copy, amend or otherwise use this source code without the explicit written *
 *  permission of the board of directors of MaidSafe.net.                                          *
 **************************************************************************************************/

#ifndef MAIDSAFE_PASSPORT_DETAIL_CONFIG_H_
#define MAIDSAFE_PASSPORT_DETAIL_CONFIG_H_


namespace maidsafe {

namespace passport {

namespace detail {

struct AnmidTag  { static const int kEnumValue = 0; };  // NOLINT (Fraser)
struct AnsmidTag { static const int kEnumValue = 1; };  // NOLINT (Fraser)
struct AntmidTag { static const int kEnumValue = 2; };  // NOLINT (Fraser)
struct AnmaidTag { static const int kEnumValue = 3; };  // NOLINT (Fraser)
struct MaidTag   { static const int kEnumValue = 4; };  // NOLINT (Fraser)
struct PmidTag   { static const int kEnumValue = 5; };  // NOLINT (Fraser)
struct MidTag    { static const int kEnumValue = 6; };  // NOLINT (Fraser)
struct SmidTag   { static const int kEnumValue = 7; };  // NOLINT (Fraser)
struct TmidTag   { static const int kEnumValue = 8; };  // NOLINT (Fraser)
struct AnmpidTag { static const int kEnumValue = 9; };  // NOLINT (Fraser)
struct MpidTag   { static const int kEnumValue = 10; };  // NOLINT (Fraser)

template<typename Tag, class Enable = void>
class Fob;

template<typename Tag>
struct MidData;

template<typename Tag>
struct TmidData;

template<typename Tag>
struct Signer {
  typedef Fob<Tag> type;
};

template<>
struct Signer<MaidTag> {
  typedef Fob<AnmaidTag> type;
};

template<>
struct Signer<PmidTag> {
  typedef Fob<MaidTag> type;
};

template<>
struct Signer<MidTag> {
  typedef Fob<AnmidTag> type;
};

template<>
struct Signer<SmidTag> {
  typedef Fob<AnsmidTag> type;
};

template<>
struct Signer<TmidTag> {
  typedef Fob<AntmidTag> type;
};

template<>
struct Signer<MpidTag> {
  typedef Fob<AnmpidTag> type;
};

}  // namespace detail

}  // namespace passport

}  // namespace maidsafe

#endif  // MAIDSAFE_PASSPORT_DETAIL_CONFIG_H_
