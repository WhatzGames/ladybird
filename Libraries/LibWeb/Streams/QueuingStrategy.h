/*
 * Copyright (c) 2023, Shannon Booth <shannon@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Optional.h>
#include <LibGC/Ptr.h>
#include <LibWeb/WebIDL/CallbackType.h>

namespace Web::Streams {

// https://streams.spec.whatwg.org/#dictdef-queuingstrategy
struct QueuingStrategy {
    Optional<double> high_water_mark;
    GC::Ptr<WebIDL::CallbackType> size;
};

}
