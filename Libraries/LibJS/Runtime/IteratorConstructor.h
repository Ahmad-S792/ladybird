/*
 * Copyright (c) 2023, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Forward.h>
#include <LibJS/Runtime/NativeFunction.h>

namespace JS {

class JS_API IteratorConstructor : public NativeFunction {
    JS_OBJECT(IteratorConstructor, NativeFunction);
    GC_DECLARE_ALLOCATOR(IteratorConstructor);

public:
    virtual void initialize(Realm&) override;

    virtual ThrowCompletionOr<Value> call() override;
    virtual ThrowCompletionOr<GC::Ref<Object>> construct(FunctionObject& new_target) override;

private:
    explicit IteratorConstructor(Realm&);

    virtual bool has_constructor() const override { return true; }

    JS_DECLARE_NATIVE_FUNCTION(from);
};

}
