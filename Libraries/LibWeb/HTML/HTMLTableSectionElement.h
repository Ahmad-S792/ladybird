/*
 * Copyright (c) 2020, the SerenityOS developers.
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/ARIA/Roles.h>
#include <LibWeb/HTML/HTMLElement.h>
#include <LibWeb/WebIDL/Types.h>

namespace Web::HTML {

class HTMLTableSectionElement final : public HTMLElement {
    WEB_PLATFORM_OBJECT(HTMLTableSectionElement, HTMLElement);
    GC_DECLARE_ALLOCATOR(HTMLTableSectionElement);

public:
    virtual ~HTMLTableSectionElement() override;

    GC::Ref<DOM::HTMLCollection> rows() const;
    WebIDL::ExceptionOr<GC::Ref<HTMLTableRowElement>> insert_row(WebIDL::Long index);
    WebIDL::ExceptionOr<void> delete_row(WebIDL::Long index);

    // https://www.w3.org/TR/html-aria/#el-tbody
    // https://www.w3.org/TR/html-aria/#el-tfoot
    // https://www.w3.org/TR/html-aria/#el-thead
    virtual Optional<ARIA::Role> default_role() const override { return ARIA::Role::rowgroup; }

private:
    HTMLTableSectionElement(DOM::Document&, DOM::QualifiedName);

    virtual bool is_html_table_section_element() const override { return true; }

    virtual void initialize(JS::Realm&) override;
    virtual void visit_edges(Cell::Visitor&) override;

    virtual bool is_presentational_hint(FlyString const&) const override;
    virtual void apply_presentational_hints(GC::Ref<CSS::CascadedProperties>) const override;

    GC::Ptr<DOM::HTMLCollection> mutable m_rows;
};

}

namespace Web::DOM {

template<>
inline bool Node::fast_is<HTML::HTMLTableSectionElement>() const { return is_html_table_section_element(); }

}
