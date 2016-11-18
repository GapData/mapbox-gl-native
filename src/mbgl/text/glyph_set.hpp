#pragma once

#include <mbgl/text/bidi.hpp>
#include <mbgl/text/glyph.hpp>
#include <mbgl/util/geometry.hpp>

namespace mbgl {

class GlyphSet {
public:
    void insert(uint32_t id, SDFGlyph&&);
    const std::map<uint32_t, SDFGlyph> &getSDFs() const;
    const Shaping getShaping(const std::u16string &string, const WritingDirection writingDirection, float maxWidth, float lineHeight,
                             float horizontalAlign, float verticalAlign, float justify,
                             float spacing, const Point<float> &translate,
                             float verticalHeight, const WritingModeType writingMode) const;
    void lineWrap(Shaping &shaping, float lineHeight, float maxWidth, float horizontalAlign,
                  float verticalAlign, float justify, const Point<float> &translate,
                  bool useBalancedIdeographicBreaking, const WritingDirection writingDirection,
                  WritingModeType writingMode) const;

private:
    std::map<uint32_t, SDFGlyph> sdfs;
};

} // end namespace mbgl
