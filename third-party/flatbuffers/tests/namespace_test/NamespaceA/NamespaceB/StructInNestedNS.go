// automatically generated, do not modify

package NamespaceB

import (
	flatbuffers "github.com/google/flatbuffers/go"
)
type StructInNestedNS struct {
	_tab flatbuffers.Struct
}

func (rcv *StructInNestedNS) Init(buf []byte, i flatbuffers.UOffsetT) {
	rcv._tab.Bytes = buf
	rcv._tab.Pos = i
}

func (rcv *StructInNestedNS) A() int32 { return rcv._tab.GetInt32(rcv._tab.Pos + flatbuffers.UOffsetT(0)) }
func (rcv *StructInNestedNS) B() int32 { return rcv._tab.GetInt32(rcv._tab.Pos + flatbuffers.UOffsetT(4)) }

func CreateStructInNestedNS(builder *flatbuffers.Builder, a int32, b int32) flatbuffers.UOffsetT {
    builder.Prep(4, 8)
    builder.PrependInt32(b)
    builder.PrependInt32(a)
    return builder.Offset()
}
