/*
 * Copyright (c) 2020, the SerenityOS developers.
 * Copyright (c) 2022, Luke Wilde <lukew@serenityos.org>
 * Copyright (c) 2023, Bastiaan van der Plaat <bastiaan.v.d.plaat@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/ARIA/Roles.h>
#include <LibWeb/HTML/HTMLElement.h>

namespace Web::HTML {

class HTMLMeterElement final : public HTMLElement {
    WEB_PLATFORM_OBJECT(HTMLMeterElement, HTMLElement);
    GC_DECLARE_ALLOCATOR(HTMLMeterElement);

public:
    virtual ~HTMLMeterElement() override;

    double value() const;
    WebIDL::ExceptionOr<void> set_value(double);
    double min() const;
    WebIDL::ExceptionOr<void> set_min(double value);
    double max() const;
    WebIDL::ExceptionOr<void> set_max(double value);
    double low() const;
    WebIDL::ExceptionOr<void> set_low(double value);
    double high() const;
    WebIDL::ExceptionOr<void> set_high(double value);
    double optimum() const;
    WebIDL::ExceptionOr<void> set_optimum(double value);

    // ^HTMLElement
    virtual void inserted() override;

    virtual void adjust_computed_style(CSS::ComputedProperties&) override;

    // https://html.spec.whatwg.org/multipage/forms.html#category-label
    virtual bool is_labelable() const override { return true; }

    // https://www.w3.org/TR/html-aria/#el-meter
    virtual Optional<ARIA::Role> default_role() const override { return ARIA::Role::meter; }

    enum class ValueState : u8 {
        Optimal,
        Suboptimal,
        EvenLessGood,
    };
    ValueState value_state() const { return m_cached_value_state; }

private:
    HTMLMeterElement(DOM::Document&, DOM::QualifiedName);

    virtual void initialize(JS::Realm&) override;
    virtual void visit_edges(Cell::Visitor&) override;

    void create_shadow_tree_if_needed();

    void update_meter_value_element();

    GC::Ptr<DOM::Element> m_meter_value_element;
    ValueState m_cached_value_state { ValueState::Optimal };
};

}
