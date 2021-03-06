/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "BlockchainUtils.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions,
                               std::vector<CachedTransaction>& transactions) {
  transactions.reserve(binaryTransactions.size());

  for (auto binaryTransaction : binaryTransactions) {
    Transaction transaction;
    if (!fromBinaryArray(transaction, binaryTransaction)) {
      return false;
    }

    transactions.emplace_back(std::move(transaction));
  }

  return true;
}

}
}
