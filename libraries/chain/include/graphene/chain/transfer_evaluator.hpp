/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once
#include <graphene/chain/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>

namespace graphene { namespace chain {

   class transfer_evaluator : public evaluator<transfer_evaluator>
   {
      public:
         typedef transfer_operation operation_type;

         void_result do_evaluate( const transfer_operation& o );
         void_result do_apply( const transfer_operation& o );
   };

   class override_transfer_evaluator : public evaluator<override_transfer_evaluator>
   {
      public:
         typedef override_transfer_operation operation_type;

         void_result do_evaluate( const override_transfer_operation& o );
         void_result do_apply( const override_transfer_operation& o );
   };

   class transfer_vault_to_wallet_evaluator : public evaluator<transfer_vault_to_wallet_evaluator>
   {
      public:
         typedef transfer_vault_to_wallet_operation operation_type;

         void_result do_evaluate( const operation_type& o );
         void_result do_apply( const operation_type& o );

      private:
         const account_balance_object* from_balance_obj_;
         const account_balance_object* to_balance_obj_;
   };

   class transfer_wallet_to_vault_evaluator : public evaluator<transfer_wallet_to_vault_evaluator>
   {
      public:
         typedef transfer_wallet_to_vault_operation operation_type;

         void_result do_evaluate( const operation_type& o );
         void_result do_apply( const operation_type& o );

      private:
         const account_balance_object* from_balance_obj_;
         const account_balance_object* to_balance_obj_;
   };

   class update_euro_limit_evaluator : public evaluator<update_euro_limit_evaluator>
   {
      public:
         typedef update_euro_limit_operation operation_type;

         void_result do_evaluate( const operation_type& op );
         void_result do_apply( const operation_type& op );

      private:
         const account_object* _account_obj = nullptr;
   };

   class remove_vault_limit_evaluator : public evaluator<remove_vault_limit_evaluator>
   {
      public:
         typedef remove_vault_limit_operation operation_type;

         void_result do_evaluate( const operation_type& op );
         void_result do_apply( const operation_type& op );

   };

} } // graphene::chain
