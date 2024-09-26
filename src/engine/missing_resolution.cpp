/*
 * Shortcircuit XT - a Surge Synth Team product
 *
 * A fully featured creative sampler, available as a standalone
 * and plugin for multiple platforms.
 *
 * Copyright 2019 - 2024, Various authors, as described in the github
 * transaction log.
 *
 * ShortcircuitXT is released under the Gnu General Public Licence
 * V3 or later (GPL-3.0-or-later). The license is found in the file
 * "LICENSE" in the root of this repository or at
 * https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Individual sections of code which comprises ShortcircuitXT in this
 * repository may also be used under an MIT license. Please see the
 * section  "Licensing" in "README.md" for details.
 *
 * ShortcircuitXT is inspired by, and shares code with, the
 * commercial product Shortcircuit 1 and 2, released by VemberTech
 * in the mid 2000s. The code for Shortcircuit 2 was opensourced in
 * 2020 at the outset of this project.
 *
 * All source for ShortcircuitXT is available at
 * https://github.com/surge-synthesizer/shortcircuit-xt
 */

#include "missing_resolution.h"

namespace scxt::engine
{
std::vector<MissingResolutionWorkItem> collectMissingResolutionWorkItems(const Engine &e)
{
    std::vector<MissingResolutionWorkItem> res;

    const auto &sm = e.getSampleManager();
    auto it = sm->samplesBegin();
    while (it != sm->samplesEnd())
    {
        const auto &[id, s] = *it;
        if (s->isMissingPlaceholder)
        {
            res.push_back({id, s->mFileName});
        }
        it++;
    }

    return res;
}
} // namespace scxt::engine