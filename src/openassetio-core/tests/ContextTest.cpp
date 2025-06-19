// SPDX-License-Identifier: Apache-2.0
// Copyright 2022-2025 The Foundry Visionmongers Ltd
#include <type_traits>

#include <catch2/catch.hpp>

#include <openassetio/Context.hpp>
#include <openassetio/macros.hpp>

OPENASSETIO_FWD_DECLARE(trait, TraitsData)
OPENASSETIO_FWD_DECLARE(managerApi, ManagerStateBase)

using openassetio::Context;

SCENARIO("Context constructor is private") {
  STATIC_REQUIRE_FALSE(std::is_constructible_v<Context, openassetio::trait::TraitsDataPtr,
                                               openassetio::managerApi::ManagerStateBasePtr>);
}

SCENARIO("Default construction") {
  GIVEN("a default constructed Context") {
    const Context::Ptr context = Context::make();

    THEN("the locale is not null") { CHECK(context->locale); }
  }
}
