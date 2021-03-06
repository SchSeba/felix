// Copyright (c) 2020 Tigera, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ut.h"
#include "bpf.h"
#include "nat.h"

static CALI_BPF_INLINE int calico_unittest_entry (struct __sk_buff *skb)
{
	/* emulate the size check that the caller would have done */
	if (skb_shorter(skb, ETH_IPV4_UDP_SIZE))
		return -1;

	return icmp_v4_ttl_exceeded(skb);
}
