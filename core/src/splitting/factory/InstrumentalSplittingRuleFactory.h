/*-------------------------------------------------------------------------------
  This file is part of generalized random forest (grf).

  grf is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grf is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grf. If not, see <http://www.gnu.org/licenses/>.
 #-------------------------------------------------------------------------------*/

#ifndef GRF_INSTRUMENTALSPLITTINGRULEFACTORY_H
#define GRF_INSTRUMENTALSPLITTINGRULEFACTORY_H


#include "splitting/factory/SplittingRuleFactory.h"

/**
 * An experimental factory that produces splitting rules specialized
 * for instrumental forests.
 *
 * In addition to performing standard regression splits, this rule applies
 * a penalty to avoid splits that are too imbalanced in terms of treatment
 * assignment or instrument. The exact penalty used  depends on the value
 * of {@link TreeOptions#get_split_penalty}.
 */
class InstrumentalSplittingRuleFactory: public SplittingRuleFactory {
public:
  InstrumentalSplittingRuleFactory();
  std::shared_ptr<SplittingRule> create(const Data* data,
                                        const TreeOptions& options);
private:
  DISALLOW_COPY_AND_ASSIGN(InstrumentalSplittingRuleFactory);
};


#endif //GRF_INSTRUMENTALSPLITTINGRULEFACTORY_H
